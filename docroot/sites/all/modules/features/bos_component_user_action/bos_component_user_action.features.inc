<?php
/**
 * @file
 * bos_component_user_action.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_user_action_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_user_action_paragraphs_info() {
  $items = array(
    'user_action' => array(
      'name' => 'User Action',
      'bundle' => 'user_action',
      'locked' => '1',
    ),
  );
  return $items;
}
