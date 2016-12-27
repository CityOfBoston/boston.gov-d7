<?php
/**
 * @file
 * bos_keyboard_shortcuts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_keyboard_shortcuts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "keyboard_shortcut" && $api == "default_keyboard_shortcut_bindings") {
    return array("version" => "1");
  }
}
