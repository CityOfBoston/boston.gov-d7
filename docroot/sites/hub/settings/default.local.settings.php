<?php

/**
 * @file
 * Local settings.
 */

$database_hostname = 'mysql';

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'hub',
  'username' => 'root',
  'password' => '',
  'host' => getenv('DRUPAL_DATABASE_HOST') ? getenv('DRUPAL_DATABASE_HOST') : 'localhost',
  'port' => '3306',
  'collation' => 'utf8_general_ci',
);

// This must match URLs in the following files for automated testing to work:
// @see build/custom/phing/hub.yml
// @see docroot/sites/sites.php
$base_url = 'http://127.0.0.1:8889';

$conf['clamav_enabled'] = 0;
$conf['clamav_enable_element_image_widget'] = 0;
$conf['clamav_enable_element_file_widget'] = 0;
$conf['cron_safe_threshold'] = 0;
$conf['error_level'] = 1;
$conf['stage_file_proxy_origin'] = 'https://thehubstg.prod.acquia-sites.com';
$conf['cache'] = FALSE;
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;

// To connect to the Acquia Solr Search environment
// Uncomment the following lines after getting the proper values from drush for these
// variable AFTER you have connected through the UI
// (admin/config/system/acquia-agent/setup) once and connected to Acquia.
//$conf['acquia_identifier'] = 'ABCD-12345';
//$conf['acquia_key'] =  'LONG-UID';
//$conf['acquia_subscription_name'] = 'City of Boston - The Hub';

// To be able to utilize the Local Apache Solr, you need to set apachesolr_read_only to 0
//$conf['apachesolr_read_only'] = "0";
