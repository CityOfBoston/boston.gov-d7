<?php
/**
 * @file
 * bos_component_map.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_map_paragraphs_info() {
  $items = array(
    'map' => array(
      'name' => 'Map',
      'bundle' => 'map',
      'locked' => '1',
    ),
  );
  return $items;
}
