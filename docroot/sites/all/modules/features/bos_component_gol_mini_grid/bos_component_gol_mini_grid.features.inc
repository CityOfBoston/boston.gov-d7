<?php
/**
 * @file
 * bos_component_gol_mini_grid.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_gol_mini_grid_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_gol_mini_grid_paragraphs_info() {
  $items = array(
    'group_of_links_mini_grid' => array(
      'name' => 'Group of Links - Mini Grid',
      'bundle' => 'group_of_links_mini_grid',
      'locked' => '1',
    ),
  );
  return $items;
}
