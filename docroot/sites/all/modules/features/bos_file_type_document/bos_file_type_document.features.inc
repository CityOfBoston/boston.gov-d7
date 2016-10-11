<?php
/**
 * @file
 * bos_file_type_document.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_file_type_document_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
