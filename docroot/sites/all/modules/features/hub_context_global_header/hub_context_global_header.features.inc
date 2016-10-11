<?php
/**
 * @file
 * hub_context_global_header.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hub_context_global_header_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
