<?php
/**
 * @file
 * bos_component_three_col_w_image.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_three_col_w_image_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_component_three_col_w_image_paragraphs_info() {
  $items = array(
    '3_column_w_image' => array(
      'name' => '3-Column w/ Image',
      'bundle' => '3_column_w_image',
      'locked' => '1',
    ),
  );
  return $items;
}
