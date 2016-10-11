<?php
/**
 * @file
 * bos_settings_advanced_page_expiration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_settings_advanced_page_expiration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
