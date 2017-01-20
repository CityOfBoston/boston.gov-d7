<?php
/**
 * @file
 * bos_content_type_tabbed_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_content_type_tabbed_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_tabbed_content'.
  $field_bases['field_tabbed_content'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tabbed_content',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
