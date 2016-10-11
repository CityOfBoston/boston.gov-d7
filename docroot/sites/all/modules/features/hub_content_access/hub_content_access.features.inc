<?php
/**
 * @file
 * hub_content_access.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hub_content_access_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
