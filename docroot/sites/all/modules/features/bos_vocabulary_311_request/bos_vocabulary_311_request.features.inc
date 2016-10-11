<?php
/**
 * @file
 * bos_vocabulary_311_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_vocabulary_311_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
