<?php
/**
 * @file
 * bos_view_api_public_notices.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_view_api_public_notices_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function bos_view_api_public_notices_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
