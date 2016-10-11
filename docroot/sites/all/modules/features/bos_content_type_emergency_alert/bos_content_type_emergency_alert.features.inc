<?php
/**
 * @file
 * bos_content_type_emergency_alert.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_emergency_alert_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bos_content_type_emergency_alert_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bos_content_type_emergency_alert_node_info() {
  $items = array(
    'emergency_alert' => array(
      'name' => t('Emergency Alert'),
      'base' => 'node_content',
      'description' => t('Emergency alerts augment the homepage status component with emergency information when an emergency is active.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
