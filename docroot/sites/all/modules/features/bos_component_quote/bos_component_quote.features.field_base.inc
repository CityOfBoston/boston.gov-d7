<?php
/**
 * @file
 * bos_component_quote.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_quote_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_quote'.
  $field_bases['field_quote'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_quote',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 101,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
