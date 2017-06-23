<?php
/**
 * @file
 * bos_component_map_esri_feed.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_map_esri_feed_paragraphs_info() {
  $items = array(
    'map_esri_feed' => array(
      'name' => 'Map ESRI Feed',
      'bundle' => 'map_esri_feed',
      'locked' => '1',
    ),
  );
  return $items;
}
