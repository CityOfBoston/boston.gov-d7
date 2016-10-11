<?php
/**
 * @file
 * bos_component_header_text.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_header_text_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|paragraphs_item|header_text|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'header_text';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header Text Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_intro_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Header Text Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_basic_information|paragraphs_item|header_text|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header Text Information');

  return $field_groups;
}
