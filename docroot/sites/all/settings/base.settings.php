<?php

/**
 * @file
 * Base settings.
 */

if (!empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    default:
      // Dynamically set base url based on Acquia environment variable.
      $domain = $_ENV['AH_SITE_NAME'] . ".prod.acquia-sites.com";
      $base_url = "https://$domain";
      $cookie_domain = ".$domain";
      break;
  }

  // Recommended setting based on Acquia load testing done on 7/13/2016.
  // Stops errors from being displayed to site users.
  $conf['error_level'] = 0;
}
