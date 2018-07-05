<?php

/**
 * @file
 * Local settings.
 */

$database_hostname = 'mysql';

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => getenv('DRUPAL_DATABASE') ? getenv('DRUPAL_DATABASE') : 'drupal',
  'username' => getenv('DRUPAL_DATABASE_USER') ? getenv('DRUPAL_DATABASE_USER') : 'root',
  'password' => getenv('DRUPAL_DATABASE_PASSWORD') ? getenv('DRUPAL_DATABASE_PASSWORD') : '',
  'host' => getenv('DRUPAL_DATABASE_HOST') ? getenv('DRUPAL_DATABASE_HOST') : 'localhost',
  'port' => getenv('DRUPAL_DATABASE_PORT') ? getenv('DRUPAL_DATABASE_PORT') : '3306',
  'collation' => 'utf8_general_ci',
);

// This must match URLs in the following files for automated testing to work:
// @see build/custom/phing/hub.yml
// @see docroot/sites/sites.php
$base_url = getenv('DRUPAL_BASE_URL') ? getenv('DRUPAL_BASE_URL') : 'http://127.0.0.1:8888';

$conf['clamav_enabled'] = 0;
$conf['clamav_enable_element_image_widget'] = 0;
$conf['clamav_enable_element_file_widget'] = 0;
$conf['cron_safe_threshold'] = 0;
$conf['error_level'] = 1;
$conf['stage_file_proxy_origin'] = 'https://www.boston.gov';
$conf['cache'] = FALSE;
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;
