<?php
/**
 * @file
 * bos_text_formats.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_text_formats_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
