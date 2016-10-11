<?php
/**
 * @file
 * bos_component_grid_of_people.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_grid_of_people_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_grid_of_people_paragraphs_info() {
  $items = array(
    'grid_of_people' => array(
      'name' => 'Grid of People',
      'bundle' => 'grid_of_people',
      'locked' => '1',
    ),
  );
  return $items;
}
