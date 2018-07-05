<?php
/**
 * @file
 * bos_component_lightbox_link.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_lightbox_link_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_lightbox_link_paragraphs_info() {
  $items = array(
    'lightbox_link' => array(
      'name' => 'Lightbox Link',
      'bundle' => 'lightbox_link',
      'locked' => '1',
    ),
  );
  return $items;
}
