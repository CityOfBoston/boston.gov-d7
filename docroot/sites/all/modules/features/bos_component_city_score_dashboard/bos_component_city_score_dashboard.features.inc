<?php
/**
 * @file
 * bos_component_city_score_dashboard.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_city_score_dashboard_paragraphs_info() {
  $items = array(
    'city_score_dashboard' => array(
      'name' => 'City Score Dashboard',
      'bundle' => 'city_score_dashboard',
      'locked' => '1',
    ),
  );
  return $items;
}
