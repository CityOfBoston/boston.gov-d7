<?php
/**
 * @file
 * bos_component_commissions_search.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_commissions_search_paragraphs_info() {
  $items = array(
    'commissions_search' => array(
      'name' => 'Commissions Search',
      'bundle' => 'commissions_search',
      'locked' => '1',
    ),
  );
  return $items;
}
