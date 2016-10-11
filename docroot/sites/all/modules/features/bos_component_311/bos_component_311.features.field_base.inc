<?php
/**
 * @file
 * bos_component_311.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_311_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_311_request'.
  $field_bases['field_311_request'] = array(
    'active' => 1,
    'cardinality' => 9,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_311_request',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          '311_request' => '311_request',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
