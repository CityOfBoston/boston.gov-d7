<?php

/**
 * @file
 * Local settings.
 */

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'drupal',
  'username' => 'root',
  'password' => 'root',
  'host' => 'localhost',
  'port' => '3306',
  'collation' => 'utf8_general_ci',
);

// This must match URLs in the following files for automated testing to work:
// @see build/custom/phing/hub.yml
// @see docroot/sites/sites.php
$base_url = 'http://127.0.0.1:8888';

$conf['clamav_enabled'] = 0;
$conf['clamav_enable_element_image_widget'] = 0;
$conf['clamav_enable_element_file_widget'] = 0;
$conf['cron_safe_threshold'] = 0;
$conf['error_level'] = 1;
$conf['stage_file_proxy_origin'] = 'https://bostonstg.prod.acquia-sites.com/';
$conf['cache'] = FALSE;
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;
