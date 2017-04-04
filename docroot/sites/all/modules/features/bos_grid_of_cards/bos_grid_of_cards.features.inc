<?php
/**
 * @file
 * bos_grid_of_cards.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_grid_of_cards_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_grid_of_cards_paragraphs_info() {
  $items = array(
    'card' => array(
      'name' => 'Card',
      'bundle' => 'card',
      'locked' => '1',
    ),
    'grid_of_cards' => array(
      'name' => 'Grid of Cards',
      'bundle' => 'grid_of_cards',
      'locked' => '1',
    ),
  );
  return $items;
}
