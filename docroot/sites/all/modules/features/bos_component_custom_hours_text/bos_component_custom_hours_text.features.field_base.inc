<?php
/**
 * @file
 * bos_component_custom_hours_text.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_custom_hours_text_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_custom_hours_text'.
  $field_bases['field_custom_hours_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_hours_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
