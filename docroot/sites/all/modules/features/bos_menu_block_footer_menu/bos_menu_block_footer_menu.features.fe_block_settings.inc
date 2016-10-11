<?php
/**
 * @file
 * bos_menu_block_footer_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function bos_menu_block_footer_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 2,
    'module' => 'menu_block',
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
      'boston_hub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'boston_hub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
