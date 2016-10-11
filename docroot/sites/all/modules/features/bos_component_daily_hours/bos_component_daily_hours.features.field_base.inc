<?php
/**
 * @file
 * bos_component_daily_hours.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_component_daily_hours_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_daily_hours'.
  $field_bases['field_daily_hours'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_daily_hours',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'office_hours',
    'settings' => array(
      'cardinality' => 2,
      'granularity' => 15,
      'hoursformat' => 1,
      'limitend' => '',
      'limitstart' => '',
      'valhrs' => 0,
    ),
    'translatable' => 0,
    'type' => 'office_hours',
  );

  return $field_bases;
}
