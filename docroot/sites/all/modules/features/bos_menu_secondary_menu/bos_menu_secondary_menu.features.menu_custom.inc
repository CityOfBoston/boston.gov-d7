<?php
/**
 * @file
 * bos_menu_secondary_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bos_menu_secondary_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-secondary-menu.
  $menus['menu-secondary-menu'] = array(
    'menu_name' => 'menu-secondary-menu',
    'title' => 'Secondary Menu',
    'description' => 'Place secondary menu links here. They will be present in the header bar. On mobile they will collapse into the off-canvas navigation.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Place secondary menu links here. They will be present in the header bar. On mobile they will collapse into the off-canvas navigation.');
  t('Secondary Menu');

  return $menus;
}
