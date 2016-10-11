<?php
/**
 * @file
 * bos_component_daily_hours.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_daily_hours_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_component_daily_hours_paragraphs_info() {
  $items = array(
    'daily_hours' => array(
      'name' => 'Daily Hours',
      'bundle' => 'daily_hours',
      'locked' => '1',
    ),
  );
  return $items;
}
