<?php
/**
 * @file
 * bos_settings_linkit_editor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_settings_linkit_editor_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
}
