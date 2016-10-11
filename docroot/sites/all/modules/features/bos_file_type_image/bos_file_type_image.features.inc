<?php
/**
 * @file
 * bos_file_type_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_file_type_image_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
