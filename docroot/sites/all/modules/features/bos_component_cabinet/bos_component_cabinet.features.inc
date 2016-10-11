<?php
/**
 * @file
 * bos_component_cabinet.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_cabinet_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_cabinet_paragraphs_info() {
  $items = array(
    'cabinet' => array(
      'name' => 'Cabinet',
      'bundle' => 'cabinet',
      'locked' => '1',
    ),
  );
  return $items;
}
