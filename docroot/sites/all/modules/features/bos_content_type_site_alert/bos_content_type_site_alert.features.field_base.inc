<?php
/**
 * @file
 * bos_content_type_site_alert.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_content_type_site_alert_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'title_field'.
  $field_bases['title_field'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'title_field',
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
    'translatable' => 1,
    'type' => 'text',
  );

  return $field_bases;
}
