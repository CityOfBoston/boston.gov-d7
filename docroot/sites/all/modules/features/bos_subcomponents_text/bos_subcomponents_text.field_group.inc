<?php
/**
 * @file
 * bos_subcomponents_text.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_subcomponents_text_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_info|paragraphs_item|text_one_column|form';
  $field_group->group_name = 'group_column_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_one_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_middle_column',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-column-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_column_info|paragraphs_item|text_one_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_info|paragraphs_item|text_three_column|form';
  $field_group->group_name = 'group_column_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_three_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_column',
      1 => 'field_middle_column',
      2 => 'field_right_column',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Column Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-column-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_column_info|paragraphs_item|text_three_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_info|paragraphs_item|text_two_column|form';
  $field_group->group_name = 'group_column_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_two_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_column_configuration',
      1 => 'field_left_column',
      2 => 'field_right_column',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-column-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_column_info|paragraphs_item|text_two_column|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Column Info');

  return $field_groups;
}
