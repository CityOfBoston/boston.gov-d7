<?php
/**
 * @file
 * bos_content_type_listing_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_content_type_listing_page_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_content_type_listing_page_node_info() {
  $items = array(
    'listing_page' => array(
      'name' => t('Listing Page'),
      'base' => 'node_content',
      'description' => t('If you need to add a listing page, utilize this content type to do so.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
