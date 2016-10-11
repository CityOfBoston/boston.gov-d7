<?php
/**
 * @file
 * bos_menu_footer_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bos_menu_translation_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu.
  $menus['menu-translation-menu'] = array(
    'menu_name' => 'menu-translation-menu',
    'title' => 'Translation',
    'description' => 'Translation links',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Translation');
  t('Translation links');

  return $menus;
}
