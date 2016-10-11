<?php
/**
 * @file
 * bos_component_grid_of_quotes.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_grid_of_quotes_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_grid_of_quotes'.
  $field_bases['field_grid_of_quotes'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_grid_of_quotes',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
