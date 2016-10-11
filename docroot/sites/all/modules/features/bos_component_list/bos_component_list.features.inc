<?php
/**
 * @file
 * bos_component_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_list_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_list_paragraphs_info() {
  $items = array(
    'list' => array(
      'name' => 'List',
      'bundle' => 'list',
      'locked' => '1',
    ),
  );
  return $items;
}
