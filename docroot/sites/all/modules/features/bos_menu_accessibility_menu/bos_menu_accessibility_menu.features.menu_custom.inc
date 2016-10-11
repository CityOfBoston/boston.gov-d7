<?php
/**
 * @file
 * bos_menu_footer_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bos_menu_accessibility_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu.
  $menus['menu-accessibility-menu'] = array(
    'menu_name' => 'menu-accessibility-menu',
    'title' => 'Accessibility',
    'description' => 'Accessibility links',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Accessibility');
  t('Accessibility links');

  return $menus;
}
