<?php
/**
 * @file
 * bos_component_map_coordinates.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_map_coordinates_paragraphs_info() {
  $items = array(
    'map_coordinates' => array(
      'name' => 'Map Coordinates',
      'bundle' => 'map_coordinates',
      'locked' => '1',
    ),
  );
  return $items;
}
