<?php
/**
 * @file
 * bos_component_election_results.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_election_results_paragraphs_info() {
  $items = array(
    'election_results' => array(
      'name' => 'Election Results',
      'bundle' => 'election_results',
      'locked' => '1',
    ),
  );
  return $items;
}
