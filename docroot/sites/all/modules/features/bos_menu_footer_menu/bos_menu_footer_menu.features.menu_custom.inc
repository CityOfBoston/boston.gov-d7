<?php
/**
 * @file
 * bos_menu_footer_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bos_menu_footer_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => 'Navigation for the footer.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer menu');
  t('Navigation for the footer.');

  return $menus;
}
