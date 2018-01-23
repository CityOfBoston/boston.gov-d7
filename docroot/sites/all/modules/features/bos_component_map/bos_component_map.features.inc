<?php
/**
 * @file
 * bos_component_map.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_map_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_map_paragraphs_info() {
  $items = array(
    'map' => array(
      'name' => 'Map',
      'bundle' => 'map',
      'locked' => '1',
    ),
  );
  return $items;
}
