<?php

/**
 * @file
 * Custom drush commands provided by Bolt.
 */

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 */
function bolt_drush_command() {
  $items = array();

  $items['check-local-settings'] = array(
    'description' => "Check local settings to ensure that things are set up properly.",
    'aliases' => array('cls'),
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
  );

  return $items;
}

/**
 * Callback for `check-local-settings` command.
 */
function drush_bolt_check_local_settings() {
  $status_table = drush_core_status();

  $local_settings_path = $status_table['root'] . '/' . $status_table['site'] . '/settings/' . 'local.settings.php';
  if (!file_exists($local_settings_path)) {
    drush_log("Could not find local settings file!", 'error');
    drush_print("Your local settings file should exist at $local_settings_path", 2);

    return FALSE;
  }
  else {
    drush_log("Found your local settings file at:", 'success');
    drush_print($local_settings_path, 2);
    drush_print();
  }

  global $base_url;

  if (strstr($base_url, 'https')) {
    if (!drush_shell_exec('curl -cacert %s', $base_url)) {
      drush_log('The SSL certificate for your local site appears to be invalid:', 'error');
      drush_print($base_url, 2);
      drush_print();
    }
  }

  $site_available = drush_shell_exec("curl -I --insecure %s", $base_url);
  if (!$site_available) {
    drush_log("Did not get response from $base_url", 'error');
    drush_print("Is your *AMP stack running?", 2);
    drush_print("Is your \$base_url set correctly in $local_settings_path?", 2);
    drush_print();
  }
  else {
    drush_log("Received http response from site:", 'success');
    drush_print($base_url, 2);
  }

  if (empty($status_table['bootstrap']) || $status_table['bootstrap'] != 'Successful') {
    drush_log('Could not bootstrap Drupal!', 'error');
    drush_print("Is your *AMP stack running?", 2);
    drush_print('Are your database credentials correct?', 2);
    drush_bolt_print_status_rows($status_table, array(
      'db-driver',
      'db-hostname',
      'db-username',
      'db-password',
      'db-name',
      'db-port',
    ));

    drush_print('Is the active PHP binary the same one that is associated with your database service?');
    drush_bolt_print_status_rows($status_table, array(
      'php-os',
      'php-bin',
      'php-conf',
    ));

    drush_print('Are you using the correct site and settings.php file?');
    drush_bolt_print_status_rows($status_table, array(
      'site',
      'drupal-settings-file',
    ));
  }
  else {
    drush_log('Bootstrapped Drupal.', 'success');
  }

  if (drush_bootstrap_max(DRUSH_BOOTSTRAP_DRUPAL_FULL)) {
    global $conf;

    if ($conf['cache']) {
      drush_log('Drupal cache is enabled. It is suggested that you disable this for local development.', 'warning');
    }
    else {
      drush_log('Drupal cache is disabled.', 'success');
    }
    if ($conf['preprocess_css']) {
      drush_log('CSS preprocessing enabled. It is suggested that you disable this for local development.', 'warning');
    }
    else {
      drush_log('CSS preprocessing is disabled.', 'success');
    }
    if ($conf['preprocess_js']) {
      drush_log('JS preprocessing is enabled. It is suggested that you disable this for local development', 'warning');
    }
    else {
      drush_log('JS preprocessing is disabled.', 'success');
    }
  }

  $home = getenv("HOME");
  if (!file_exists("$home/.nvm")) {
    drush_log('NVM does not exist. Install using the following commands:', 'error');
    drush_print('curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.31.0/install.sh | bash', 2);
    drush_print('source ~/.bashrc', 2);
    drush_print('nvm install 0.12.7', 2);
    drush_print('nvm use 0.12.7', 2);
  }
  else {
    drush_log("NVM exists.", 'success');
  }

  drush_include_engine('drupal', 'update');
  update_main_prepare();
  list($pending, $start) = updatedb_status();
  if ($pending) {
    drush_log("There are pending database updates", 'error');
    drush_print("Run `drush updb` to execute the updates.", 2);
  }
  else {
    drush_log("There are no pending database updates.", 'success');
  }

}

/**
 * Indents a key-value row.
 *
 * @param mixed $input
 *   An array of key-value rows, or a string.
 *
 * @param $metadata
 *   The formatting metadata.
 *
 * @return array|string
 *   The prefixed output.
 */
function drush_bolt_indent_filter($input, $metadata) {
  $indent = !empty($metadata['indent']) ? $metadata['indent'] : 2;
  $prefix = str_repeat(' ', $indent);
  if (is_array($input)) {
    foreach ($input as $key => $value) {
      $input[$prefix . $key] = $value;
      unset($input[$key]);
    }
  }
  else {
    $input = $prefix . $input;
  }

  return $input;
}

/**
 * Prints selected rows from the status table.
 *
 * @param array $status_table
 *   The status table returned by drush_core_status().
 *
 * @param array $keys
 *   An array of keys for the rows to print.
 */
function drush_bolt_print_status_rows($status_table, $keys) {
  $intersection = array_intersect_key($status_table, array_flip($keys));
  $output = drush_format($intersection, array(
    'format' => 'key-value',
    'formatted-filter' => array(
      'drush_bolt_indent_filter',
    ),
    'indent' => 2,
  ));
  drush_print($output);
}
