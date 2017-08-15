<?php
/**
 * @file
 * bos_component_list.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_list_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|paragraphs_item|list|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'List Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_list',
      3 => 'field_short_title',
      4 => 'field_component_theme',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'List Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_basic_information|paragraphs_item|list|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('List Information');

  return $field_groups;
}
