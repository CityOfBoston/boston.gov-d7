<?php
/**
 * @file
 * bos_content_type_how_to.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_how_to_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_content_type_how_to_node_info() {
  $items = array(
    'how_to' => array(
      'name' => t('How-To'),
      'base' => 'node_content',
      'description' => t('Add a how-to content item.'),
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
function bos_content_type_how_to_paragraphs_info() {
  $items = array(
    'how_to_contact_step' => array(
      'name' => 'How-To Contact Step',
      'bundle' => 'how_to_contact_step',
      'locked' => '1',
    ),
    'how_to_tab' => array(
      'name' => 'How-To Tab',
      'bundle' => 'how_to_tab',
      'locked' => '1',
    ),
    'how_to_text_step' => array(
      'name' => 'How-To Text Step',
      'bundle' => 'how_to_text_step',
      'locked' => '1',
    ),
  );
  return $items;
}
