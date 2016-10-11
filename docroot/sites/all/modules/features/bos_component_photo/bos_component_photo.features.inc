<?php
/**
 * @file
 * bos_component_photo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_photo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_photo_paragraphs_info() {
  $items = array(
    'photo' => array(
      'name' => 'Photo',
      'bundle' => 'photo',
      'locked' => '1',
    ),
  );
  return $items;
}
