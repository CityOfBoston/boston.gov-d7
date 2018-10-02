<?php
/**
 * @file
 * bos_commissions_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bos_commissions_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function bos_commissions_search_paragraphs_info() {
  $items = array(
    'commissions_search' => array(
      'name' => 'Commissions Search',
      'bundle' => 'commissions_search',
      'locked' => '1',
    ),
  );
  return $items;
}
