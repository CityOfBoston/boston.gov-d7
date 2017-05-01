<?php
/**
 * @file
 * bos_component_text.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_text_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_text_blocks'
  $field_bases['field_text_blocks'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_text_blocks',
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
