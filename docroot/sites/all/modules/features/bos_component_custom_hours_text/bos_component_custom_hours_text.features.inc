<?php
/**
 * @file
 * bos_component_custom_hours_text.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_custom_hours_text_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_custom_hours_text_paragraphs_info() {
  $items = array(
    'custom_hours_text' => array(
      'name' => 'Custom Hours Text',
      'bundle' => 'custom_hours_text',
      'locked' => '1',
    ),
  );
  return $items;
}
