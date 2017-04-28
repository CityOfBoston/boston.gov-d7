<?php
/**
 * @file
 * bos_drawers_component.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_drawers_component_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_drawer'
  $field_bases['field_drawer'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_drawer',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
