<?php
/**
 * @file
 * bos_component_daily_hours.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_daily_hours_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_daily_hours|paragraphs_item|daily_hours|form';
  $field_group->group_name = 'group_daily_hours';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'daily_hours';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Daily Hours',
    'weight' => '0',
    'children' => array(
      0 => 'field_daily_hours',
      1 => 'field_hours_icon',
      2 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-daily-hours field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_daily_hours|paragraphs_item|daily_hours|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Daily Hours');

  return $field_groups;
}
