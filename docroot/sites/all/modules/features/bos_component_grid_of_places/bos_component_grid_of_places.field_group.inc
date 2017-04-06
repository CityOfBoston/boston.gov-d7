<?php
/**
 * @file
 * bos_component_grid_of_places.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_grid_of_places_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|paragraphs_item|grid_of_places|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_places';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_details|paragraphs_item|grid_of_places|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_places|paragraphs_item|grid_of_places|form';
  $field_group->group_name = 'group_places';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_places';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Places',
    'weight' => '1',
    'children' => array(
      0 => 'field_place',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Places',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_places|paragraphs_item|grid_of_places|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme|paragraphs_item|grid_of_places|form';
  $field_group->group_name = 'group_theme';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_places';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Theme',
    'weight' => '2',
    'children' => array(
      0 => 'field_component_theme',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-theme field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_theme|paragraphs_item|grid_of_places|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Places');
  t('Theme');

  return $field_groups;
}
