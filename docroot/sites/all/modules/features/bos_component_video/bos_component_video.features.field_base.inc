<?php
/**
 * @file
 * bos_component_video.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_video_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_is_channel'.
  $field_bases['field_is_channel'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_is_channel',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'false' => 'No',
        'true' => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
