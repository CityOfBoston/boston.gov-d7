<?php

/**
 * @file
 * Examples and dependenct methods for IP address and basic authentication
 * application restrictions on Acquia Cloud environments.
 *
 * The site lockdown process happens by calling ac_protect_this_site();
 * after defining desired $conf variables.
 *
 * Whitelist / blacklist IPs may use any of the following syntax:
 * - CIDR (107.0.255.128/27)
 * - Range (121.91.2.5-121-121.91.3.4)
 * - Wildcard (36.222.120.*)
 * - Single  (9.80.226.4)
 *
 * Business logic:
 * - With no $conf values set, ``ac_protect_this_site();`` will do nothing.
 * - If the path is marked as restricted, all users not on the whitelist will
 *   receive access denied.
 * - If a user's IP is on the blacklist and not on the whitelist they will
 *   receive access denied.
 * - Securing the site requires entries in both $conf['ah_whitelist'] and
 *   $conf['ah_restricted_paths'].
 */

 // Include Boston.gov settings.
 if (isset($_ENV['AH_SITE_ENVIRONMENT']) && file_exists("/mnt/gfs/{$ac_subname}.{$_ENV['AH_SITE_ENVIRONMENT']}/nobackup/boston.settings.php")) {
   require "/mnt/gfs/{$ac_subname}.{$_ENV['AH_SITE_ENVIRONMENT']}/nobackup/auth.settings.php";
 }
 
/**
 * Whitelisted IP addresses: An array of IP addresses to allow on to the site.
 *
 * Examples:
 *
 * @code
 * $conf['ah_whitelist'] = array(
 *   '36.222.120.*',
 *   '107.0.255.128/27',
 * );
 * @endcode
 *
 * @code
 * $conf['ah_whitelist'] = array(
 *   '107.0.255.128/27',
 *   '64.119.156.88/29',
 *   '64.119.149.232/29',
 *   '107.20.238.9',
 *   '70.102.97.2/30',
 *   '50.196.16.189/29',
 * );
 */
$conf['ah_whitelist'] = array();

/**
 * Blacklisted IP addresses: An array of IP addresses to deny access to the site.
 *
 * Examples:
 *
 * @code
 * $conf['ah_blacklist'] = array(
 *   '12.13.14.15',
 * );
 * @endcode
 */
$conf['ah_blacklist'] = array();

/**
 * Restricted paths: Paths which may not be accessed unless the user is on the
 * IP whitelist.
 *
 * Examples:
 *
 * @code
 * $conf['ah_restricted_paths'] = array(
 *   '*',
 * );
 * @endcode
 *
 * @code
 * $conf['ah_restricted_paths'] = array(
 *   'user',
 *   'user/*',
 *   'admin',
 *   'admin/*',
 * );
 * @endcode
 */
$conf['ah_restricted_paths'] = array();

/**
 * No-cache paths: Paths we should explicitly never cache.
 *
 * Examples:
 *
 * @code
 * $conf['ah_paths_no_cache'] = array(
 *   'api',
 * );
 * @endcode
 */
$conf['ah_paths_no_cache'] = array();

/**
 * Skip-authentication paths: Skip basic authentication for these paths.
 *
 * Examples:
 *
 * @code
 * $conf['ah_paths_skip_auth'] = array(
 *   'api',
 * );
 * @endcode
 */
$conf['ah_paths_skip_auth'] = array();

/**
 * Protect this site in non-production Acquia environments.
 */
if (file_exists('/var/www/site-php')) {

  if(!defined('DRUPAL_ROOT')) {
    define('DRUPAL_ROOT', getcwd());
  }

  if (isset($_ENV['AH_NON_PRODUCTION']) && $_ENV['AH_NON_PRODUCTION']) {
    ac_protect_this_site();
  }
}

/**
 * Utility methods for use in protecting an environment via basic auth or IP whitelist.
 */

function ac_protect_this_site() {
  global $conf;
  $client_ip = ip_address();

  // Test if we are using drush (command-line interface)
  $cli = drupal_is_cli();

  // Default to not skipping the auth check
  $skip_auth_check = FALSE;

  // Is the user on the VPN? Default to FALSE.
  $on_vpn = $cli ? TRUE : FALSE;

  if (!empty($client_ip) && !empty($conf['ah_whitelist'])) {
    $on_vpn = ah_ip_in_list($client_ip, $conf['ah_whitelist']);
    $skip_auth_check = $skip_auth_check || $on_vpn;
  }

  // If the IP is not explicitly whitelisted check to see if the IP is blacklisted.
  if (!$on_vpn && !empty($client_ip) && !empty($conf['ah_blacklist'])) {
    if (ah_ip_in_list($client_ip, $conf['ah_blacklist'])) {
      ah_page_403($client_ip);
    }
  }

  // Check if we should skip auth check for this page.
  if (ah_path_skip_auth()) {
    $skip_auth_check = TRUE;
  }

  // Check if we should disable cache for this page.
  if (ah_path_no_cache()) {
    $conf['page_cache_maximum_age'] = 0;
  }

  // Is the page restricted to whitelist only? Default to FALSE.
  $restricted_page = FALSE;

  // Check to see whether this page is restricted.
  if (!empty($conf['ah_restricted_paths']) && ah_paths_restrict()) {
    $restricted_page = TRUE;
  }

  $protect_ip = !empty($conf['ah_whitelist']);
  $protect_password = !empty($conf['ah_basic_auth_credentials']);

  // Do not protect command line requests, e.g. Drush.
  if ($cli) {
    $protect_ip = FALSE;
    $protect_password = FALSE;
  }

  // Un-comment to disable protection, e.g. for load tests.
  // $skip_auth_check = TRUE;
  // $on_vpn = TRUE;

  // If not on whitelisted IP prevent access to protected pages.
  if ($protect_ip && !$on_vpn && $restricted_page) {
    ah_page_403($client_ip);
  }

  // If not skipping auth, check basic auth.
  if ($protect_password && !$skip_auth_check) {
    ah_check_basic_auth();
  }
}

/**
 * Output a 403 (forbidden access) response.
 */
function ah_page_403($client_ip) {
  header('HTTP/1.0 403 Forbidden');
  print "403 Forbidden: Access denied ($client_ip)";
  exit;
}

/**
 * Output a 401 (unauthorized) response.
 */
function ah_page_401($client_ip) {
  header('WWW-Authenticate: Basic realm="This site is protected"');
  header('HTTP/1.0 401 Unauthorized');
  print "401 Unauthorized: Access denied ($client_ip)";
  exit;
}

/**
 * Check basic auth against allowed values.
 */
function ah_check_basic_auth() {
  global $conf;

  $authorized = FALSE;
  $php_auth_user = isset($_SERVER['PHP_AUTH_USER']) ? $_SERVER['PHP_AUTH_USER'] : NULL;
  $php_auth_pw = isset($_SERVER['PHP_AUTH_PW']) ? $_SERVER['PHP_AUTH_PW'] : NULL;
  $credentials = isset($conf['ah_basic_auth_credentials']) ? $conf['ah_basic_auth_credentials'] : NULL;

  if ($php_auth_user && $php_auth_pw && !empty($credentials)) {
    if (isset($credentials[$php_auth_user]) && $credentials[$php_auth_user] == $php_auth_pw) {
      $authorized = TRUE;
    }
  }

  if ($authorized) {
    return;
  }

  // Always fall back to 401.
  ah_page_401(ip_address());
}

/**
 * Determine if the current path is in the list of paths to not cache.
 */
function ah_path_no_cache() {
  global $conf;

  $q = isset($_GET['q']) ? $_GET['q'] : NULL;
  $paths = isset($conf['ah_paths_no_cache']) ? $conf['ah_paths_no_cache'] : NULL;
  if (!empty($q) && !empty($paths)) {
    foreach ($paths as $path) {
      if ($q == $path || strpos($q, $path) === 0) {
        return TRUE;
      }
    }
  }
}

/**
 * Determine if the current path is in the list of paths on which to not check
 * auth.
 */
function ah_path_skip_auth() {
  global $conf;

  $q = isset($_GET['q']) ? $_GET['q'] : NULL;
  $paths = isset($conf['ah_paths_skip_auth']) ? $conf['ah_paths_skip_auth'] : NULL;
  if (!empty($q) && !empty($paths)) {
    foreach ($paths as $path) {
      if ($q == $path || strpos($q, $path) === 0) {
        return TRUE;
      }
    }
  }
}

/**
 * Check whether a path has been restricted.
 *
 */
function ah_paths_restrict() {
  global $conf;

  if (isset($_GET['q'])) {

    // Borrow some code from drupal_match_path()
    foreach ($conf['ah_restricted_paths'] as &$path) {
      $path = preg_quote($path, '/');
    }

    $paths = preg_replace('/\\\\\*/', '.*', $conf['ah_restricted_paths']);
    $paths = '/^(' . join('|', $paths) . ')$/';

    // If this is a restricted path, return TRUE.
    if (preg_match($paths, $_GET['q'])) {
      // Do not cache restricted paths
      $conf['page_cache_maximum_age'] = 0;
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Determine if the IP is within the ranges defined in the white/black list.
 */
function ah_ip_in_list($ip, $list) {
  foreach ($list as $item) {

    // Match IPs in CIDR format.
    if (strpos($item, '/') !== false) {
      list($range, $mask) = explode('/', $item);

      // Take the binary form of the IP and range.
      $ip_dec = ip2long($ip);
      $range_dec = ip2long($range);

      // Verify the given IPs are valid IPv4 addresses
      if (!$ip_dec || !$range_dec) {
        continue;
      }

      // Create the binary form of netmask.
      $mask_dec = ~ (pow(2, (32 - $mask)) - 1);

      // Run a bitwise AND to determine whether the IP and range exist
      // within the same netmask.
      if (($mask_dec & $ip_dec) == ($mask_dec & $range_dec)) {
        return TRUE;
      }
    }

    // Match against wildcard IPs or IP ranges.
    elseif (strpos($item, '*') !== false || strpos($item, '-') !== false) {

      // Construct a range from wildcard IPs
      if (strpos($item, '*') !== false) {
        $item = str_replace('*', 0, $item) . '-' . str_replace('*', 255, $item);
      }

      // Match against ranges by converting to long IPs.
      list($start, $end) = explode('-', $item);

      $start_dec = ip2long($start);
      $end_dec = ip2long($end);
      $ip_dec = ip2long($ip);

      // Verify the given IPs are valid IPv4 addresses
      if (!$start_dec || !$end_dec || !$ip_dec) {
        continue;
      }

      if ($start_dec <= $ip_dec && $ip_dec <= $end_dec) {
        return TRUE;
      }
    }

    // Match against single IPs
    elseif ($ip === $item) {
      return TRUE;
    }
  }
  return FALSE;
}
