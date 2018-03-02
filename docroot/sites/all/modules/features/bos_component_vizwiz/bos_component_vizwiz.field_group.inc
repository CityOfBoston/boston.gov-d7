<?php
/**
 * @file
 * bos_component_vizwiz.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_vizwiz_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vizwiz_json|paragraphs_item|vizwiz|form';
  $field_group->group_name = 'group_vizwiz_json';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'vizwiz';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vizwiz';
  $field_group->data = array(
    'label' => 'Auto-created JSON',
    'weight' => '8',
    'children' => array(
      0 => 'field_vizwiz_json',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Auto-created JSON',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-vizwiz-json field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_vizwiz_json|paragraphs_item|vizwiz|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vizwiz|paragraphs_item|vizwiz|form';
  $field_group->group_name = 'group_vizwiz';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'vizwiz';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'VizWiz Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_vizwiz',
      1 => 'group_vizwiz_json',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'VizWiz Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-vizwiz field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_vizwiz|paragraphs_item|vizwiz|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Auto-created JSON');
  t('VizWiz Info');

  return $field_groups;
}
