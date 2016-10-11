<?php
/**
 * @file
 * bos_component_gol_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_gol_list_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_component_gol_list_paragraphs_info() {
  $items = array(
    'gol_list_links' => array(
      'name' => 'List Links',
      'bundle' => 'gol_list_links',
      'locked' => '1',
    ),
    'group_of_links_list' => array(
      'name' => 'Group of Links - List',
      'bundle' => 'group_of_links_list',
      'locked' => '1',
    ),
  );
  return $items;
}
