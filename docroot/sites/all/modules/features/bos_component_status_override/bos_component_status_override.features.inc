<?php
/**
 * @file
 * bos_component_status_override.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_status_override_paragraphs_info() {
  $items = array(
    'status_override' => array(
      'name' => 'Status Override',
      'bundle' => 'status_override',
      'locked' => '1',
    ),
  );
  return $items;
}
