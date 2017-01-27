<?php
/**
 * @file
 * bos_component_card.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_card_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_card_paragraphs_info() {
  $items = array(
    'card' => array(
      'name' => 'Card',
      'bundle' => 'card',
      'locked' => '1',
    ),
  );
  return $items;
}
