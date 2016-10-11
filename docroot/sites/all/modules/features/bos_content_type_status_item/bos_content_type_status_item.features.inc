<?php
/**
 * @file
 * bos_content_type_status_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_status_item_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_content_type_status_item_node_info() {
  $items = array(
    'status_item' => array(
      'name' => t('Status Item'),
      'base' => 'node_content',
      'description' => t('Create a status item to be displayed dynamically through status views. Status views can be selected through a List component and placed on a page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_content_type_status_item_paragraphs_info() {
  $items = array(
    'message_for_the_day' => array(
      'name' => 'Message for the Day',
      'bundle' => 'message_for_the_day',
      'locked' => '1',
    ),
  );
  return $items;
}
