<?php
/**
 * @file
 * bos_component_featured_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_featured_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_featured_item_paragraphs_info() {
  $items = array(
    'featured_item' => array(
      'name' => 'Featured Item',
      'bundle' => 'featured_item',
      'locked' => '1',
    ),
  );
  return $items;
}
