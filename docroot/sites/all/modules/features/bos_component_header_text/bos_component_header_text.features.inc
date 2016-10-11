<?php
/**
 * @file
 * bos_component_header_text.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_header_text_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_header_text_paragraphs_info() {
  $items = array(
    'header_text' => array(
      'name' => 'Header Text',
      'bundle' => 'header_text',
      'locked' => '1',
    ),
  );
  return $items;
}
