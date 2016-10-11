<?php
/**
 * @file
 * bos_component_news_announcements.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_news_announcements_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_news_announcements_paragraphs_info() {
  $items = array(
    'news_announcements' => array(
      'name' => 'News & Announcements',
      'bundle' => 'news_announcements',
      'locked' => '1',
    ),
  );
  return $items;
}
