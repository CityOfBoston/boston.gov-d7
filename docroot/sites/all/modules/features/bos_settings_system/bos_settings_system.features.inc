<?php
/**
 * @file
 * bos_settings_system.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_settings_system_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
