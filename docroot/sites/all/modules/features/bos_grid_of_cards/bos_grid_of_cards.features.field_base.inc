<?php
/**
 * @file
 * bos_grid_of_cards.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_grid_of_cards_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_component_theme'.
  $field_bases['field_component_theme'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_component_theme',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'g' => 'Grey',
        'w' => 'White',
        'b' => 'Blue',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
