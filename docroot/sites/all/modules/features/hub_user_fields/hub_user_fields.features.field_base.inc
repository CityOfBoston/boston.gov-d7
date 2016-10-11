<?php
/**
 * @file
 * hub_user_fields.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hub_user_fields_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_application_id_list'.
  $field_bases['field_application_id_list'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_application_id_list',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 1024,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
