<?php
/**
 * @file
 * bos_drawers_component.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_drawers_component_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_drawers_component_paragraphs_info() {
  $items = array(
    'drawers' => array(
      'name' => 'Drawers',
      'bundle' => 'drawers',
      'locked' => '1',
    ),
  );
  return $items;
}
