<?php
/**
 * @file
 * bos_component_grid_of_quotes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_grid_of_quotes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_grid_of_quotes_paragraphs_info() {
  $items = array(
    'grid_of_quotes' => array(
      'name' => 'Grid of Quotes',
      'bundle' => 'grid_of_quotes',
      'locked' => '1',
    ),
  );
  return $items;
}
