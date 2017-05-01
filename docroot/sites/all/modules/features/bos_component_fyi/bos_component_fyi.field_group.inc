<?php
/**
 * @file
 * bos_component_fyi.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_fyi_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fyi_info|paragraphs_item|fyi|form';
  $field_group->group_name = 'group_fyi_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'fyi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FYI Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_extra_info',
      1 => 'field_icon',
      2 => 'field_link',
      3 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fyi-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_fyi_info|paragraphs_item|fyi|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('FYI Info');

  return $field_groups;
}
