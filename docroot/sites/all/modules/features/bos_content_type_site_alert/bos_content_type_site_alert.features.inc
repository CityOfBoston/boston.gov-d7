<?php
/**
 * @file
 * bos_content_type_site_alert.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_site_alert_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_content_type_site_alert_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bos_content_type_site_alert_node_info() {
  $items = array(
    'site_alert' => array(
      'name' => t('Site Alert'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The site alert is used to inform constituents of something important on every page of the site. It displays below the header in either blue or red.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
