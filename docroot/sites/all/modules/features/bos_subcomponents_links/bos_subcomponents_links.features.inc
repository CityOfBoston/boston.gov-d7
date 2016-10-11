<?php
/**
 * @file
 * bos_subcomponents_links.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_subcomponents_links_ctools_plugin_api($module = NULL, $api = NULL) {
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
function bos_subcomponents_links_paragraphs_info() {
  $items = array(
    'document' => array(
      'name' => 'Document',
      'bundle' => 'document',
      'locked' => '1',
    ),
    'external_link' => array(
      'name' => 'External Link',
      'bundle' => 'external_link',
      'locked' => '1',
    ),
    'internal_link' => array(
      'name' => 'Internal Link',
      'bundle' => 'internal_link',
      'locked' => '1',
    ),
  );
  return $items;
}
