<?php
/**
 * @file
 * bos_drawer_component.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_drawer_component_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_drawer_info|paragraphs_item|drawer|form';
  $field_group->group_name = 'group_drawer_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'drawer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Drawer Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_short_description',
      1 => 'field_text_blocks',
      2 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Drawer Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-drawer-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_drawer_info|paragraphs_item|drawer|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Drawer Info');

  return $field_groups;
}
