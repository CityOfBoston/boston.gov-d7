<?php
/**
 * @file
 * bos_content_type_site_alert.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function bos_content_type_site_alert_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-site_alert-block_site_alert'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'site_alert-block_site_alert',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'boston' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'boston',
        'weight' => 0,
      ),
      'boston_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'boston_admin',
        'weight' => 0,
      ),
      'boston_public' => array(
        'region' => 'site_alert',
        'status' => 1,
        'theme' => 'boston_public',
        'weight' => -27,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
