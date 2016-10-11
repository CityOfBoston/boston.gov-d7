<?php
/**
 * @file
 * bos_content_type_emergency_alert.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_emergency_alert_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_emergency_alert_basic_info|node|emergency_alert|form';
  $field_group->group_name = 'group_emergency_alert_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'emergency_alert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_description',
      1 => 'field_link',
      2 => 'field_updated_date',
      3 => 'field_theme',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_emergency_alert_basic_info|node|emergency_alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_emergency_alert_stat_overr|node|emergency_alert|form';
  $field_group->group_name = 'group_emergency_alert_stat_overr';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'emergency_alert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status Overrides',
    'weight' => '4',
    'children' => array(
      0 => 'field_status_overrides',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_emergency_alert_stat_overr|node|emergency_alert|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Information');
  t('Status Overrides');

  return $field_groups;
}
