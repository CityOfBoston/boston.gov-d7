<?php
/**
 * @file
 * bos_content_type_procurement_advertisement.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_procurement_advertisement_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_content_type_procurement_advertisement_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bos_content_type_procurement_advertisement_node_info() {
  $items = array(
    'procurement_advertisement' => array(
      'name' => t('Procurement Advertisement'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
