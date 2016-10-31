<?php
/**
 * @file
 * bos_content_type_public_notice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_public_notice_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bos_content_type_public_notice_node_info() {
  $items = array(
    'public_notice' => array(
      'name' => t('Public Notice'),
      'base' => 'node_content',
      'description' => t('A content type for displaying public notices.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
