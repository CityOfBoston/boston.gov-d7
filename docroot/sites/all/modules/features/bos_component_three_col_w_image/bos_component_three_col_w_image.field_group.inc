<?php
/**
 * @file
 * bos_component_three_col_w_image.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_three_col_w_image_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_three_column_info|paragraphs_item|3_column_w_image|form';
  $field_group->group_name = 'group_three_column_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = '3_column_w_image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Three Column Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_columns',
      1 => 'field_component_title',
      2 => 'field_contact',
      3 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Three Column Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-three-column-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_three_column_info|paragraphs_item|3_column_w_image|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Three Column Info');

  return $field_groups;
}
