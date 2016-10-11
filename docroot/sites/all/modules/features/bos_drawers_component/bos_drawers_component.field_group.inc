<?php
/**
 * @file
 * bos_drawers_component.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_drawers_component_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_drawers_info|paragraphs_item|drawers|form';
  $field_group->group_name = 'group_drawers_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'drawers';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Drawers Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_drawer',
      3 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Drawers Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-drawers-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_drawers_info|paragraphs_item|drawers|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Drawers Info');

  return $field_groups;
}
