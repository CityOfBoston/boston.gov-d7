<?php
/**
 * @file
 * bos_component_311.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_311_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_311_info|paragraphs_item|bos311|form';
  $field_group->group_name = 'group_311_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'bos311';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '311 Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_311_request',
      1 => 'field_component_title',
      2 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '311 Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-311-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_311_info|paragraphs_item|bos311|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('311 Info');

  return $field_groups;
}
