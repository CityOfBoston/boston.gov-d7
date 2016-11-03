<?php
/**
 * @file
 * bos_api_public_notice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_api_public_notice_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
