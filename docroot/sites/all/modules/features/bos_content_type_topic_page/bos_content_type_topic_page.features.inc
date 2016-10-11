<?php
/**
 * @file
 * bos_content_type_topic_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_topic_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bos_content_type_topic_page_node_info() {
  $items = array(
    'topic_page' => array(
      'name' => t('Guide'),
      'base' => 'node_content',
      'description' => t('Guides are the primary navigation pages for the website. Topic pages aggregate information about a topic to let a user know what information is here.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
