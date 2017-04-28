<?php
/**
 * @file
 * bos_change_log.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_change_log_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bos_change_log_node_info() {
  $items = array(
    'change' => array(
      'name' => t('Change'),
      'base' => 'node_content',
      'description' => t('The basis of a change log for Boston.gov and The Hub.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
