<?php
/**
 * @file
 * bos_component_transaction_grid.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_component_transaction_grid_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_transaction_grid_paragraphs_info() {
  $items = array(
    'transaction_grid' => array(
      'name' => 'Transaction Grid',
      'bundle' => 'transaction_grid',
      'locked' => '1',
    ),
  );
  return $items;
}
