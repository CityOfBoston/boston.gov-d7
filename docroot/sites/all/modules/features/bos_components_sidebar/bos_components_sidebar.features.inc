<?php
/**
 * @file
 * bos_components_sidebar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_components_sidebar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_components_sidebar_paragraphs_info() {
  $items = array(
    'sidebar_item' => array(
      'name' => 'Sidebar Item',
      'bundle' => 'sidebar_item',
      'locked' => '1',
    ),
    'sidebar_item_w_icon' => array(
      'name' => 'Sidebar Item w/ Icon',
      'bundle' => 'sidebar_item_w_icon',
      'locked' => '1',
    ),
    'social_media_links' => array(
      'name' => 'Social Media Links',
      'bundle' => 'social_media_links',
      'locked' => '1',
    ),
    'social_networking' => array(
      'name' => 'Social Media Link',
      'bundle' => 'social_networking',
      'locked' => '1',
    ),
  );
  return $items;
}
