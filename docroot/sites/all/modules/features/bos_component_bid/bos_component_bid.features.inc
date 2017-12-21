<?php
/**
 * @file
 * bos_component_bid.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_bid_paragraphs_info() {
  $items = array(
    'bid' => array(
      'name' => 'Bid',
      'bundle' => 'bid',
      'locked' => '1',
    ),
  );
  return $items;
}
