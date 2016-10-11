<?php
/**
 * @file
 * bos_component_grid_of_topics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_grid_of_topics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_grid_of_topics_paragraphs_info() {
  $items = array(
    'grid_of_topics' => array(
      'name' => 'Grid of Guides',
      'bundle' => 'grid_of_topics',
      'locked' => '1',
    ),
  );
  return $items;
}
