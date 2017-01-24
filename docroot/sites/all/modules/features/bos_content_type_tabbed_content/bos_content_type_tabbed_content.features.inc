<?php
/**
 * @file
 * bos_content_type_tabbed_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_tabbed_content_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_content_type_tabbed_content_node_info() {
  $items = array(
    'tabbed_content' => array(
      'name' => t('Tabbed Content'),
      'base' => 'node_content',
      'description' => t('A page with a tabbed interface.'),
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
function bos_content_type_tabbed_content_paragraphs_info() {
  $items = array(
    'tabbed_content_tab' => array(
      'name' => 'Tabbed Content Tab',
      'bundle' => 'tabbed_content_tab',
      'locked' => '1',
    ),
  );
  return $items;
}
