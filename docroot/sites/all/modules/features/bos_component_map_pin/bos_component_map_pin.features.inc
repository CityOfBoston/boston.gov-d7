<?php
/**
 * @file
 * bos_component_map_pin.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_map_pin_paragraphs_info() {
  $items = array(
    'map_pin' => array(
      'name' => 'Map Pin',
      'bundle' => 'map_pin',
      'locked' => '1',
    ),
  );
  return $items;
}
