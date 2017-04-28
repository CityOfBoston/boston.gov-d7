<?php
/**
 * @file
 * bos_component_featured_topics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_featured_topics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_featured_topics_paragraphs_info() {
  $items = array(
    'featured_topics' => array(
      'name' => 'Featured Guides',
      'bundle' => 'featured_topics',
      'locked' => '1',
    ),
  );
  return $items;
}
