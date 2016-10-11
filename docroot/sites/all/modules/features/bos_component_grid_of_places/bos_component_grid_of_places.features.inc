<?php
/**
 * @file
 * bos_component_grid_of_places.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_grid_of_places_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_grid_of_places_paragraphs_info() {
  $items = array(
    'grid_of_places' => array(
      'name' => 'Grid of Places',
      'bundle' => 'grid_of_places',
      'locked' => '1',
    ),
  );
  return $items;
}
