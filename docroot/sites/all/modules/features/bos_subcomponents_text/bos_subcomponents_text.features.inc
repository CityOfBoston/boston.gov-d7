<?php
/**
 * @file
 * bos_subcomponents_text.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_subcomponents_text_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_subcomponents_text_paragraphs_info() {
  $items = array(
    'text_one_column' => array(
      'name' => 'One Column Text',
      'bundle' => 'text_one_column',
      'locked' => '1',
    ),
    'text_three_column' => array(
      'name' => 'Three Column Text',
      'bundle' => 'text_three_column',
      'locked' => '1',
    ),
    'text_two_column' => array(
      'name' => 'Two Column Text',
      'bundle' => 'text_two_column',
      'locked' => '1',
    ),
  );
  return $items;
}
