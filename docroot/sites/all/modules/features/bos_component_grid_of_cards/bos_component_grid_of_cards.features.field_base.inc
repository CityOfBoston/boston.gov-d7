<?php
/**
 * @file
 * bos_component_grid_of_cards.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_grid_of_cards_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_children'.
  $field_bases['field_children'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_children',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
