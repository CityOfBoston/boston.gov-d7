<?php
/**
 * @file
 * bos_component_map.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_map_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_map|paragraphs_item|map|form';
  $field_group->group_name = 'group_map';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'map';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Map Component',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_extra_info',
      3 => 'field_map',
      4 => 'field_map_default_coordinates',
      5 => 'field_map_options',
      6 => 'field_map_point_of_interest',
      7 => 'field_map_type',
      8 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-map field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_map|paragraphs_item|map|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Map Component');

  return $field_groups;
}
