<?php
/**
 * @file
 * hub_content_type_application.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hub_content_type_application_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_application_id'.
  $field_bases['field_application_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_application_id',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
