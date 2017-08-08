<?php
/**
 * @file
 * bos_grid_of_cards.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_grid_of_cards_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cards|paragraphs_item|grid_of_cards|form';
  $field_group->group_name = 'group_cards';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_cards';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cards',
    'weight' => '1',
    'children' => array(
      0 => 'field_drawer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Cards',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_cards|paragraphs_item|grid_of_cards|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|paragraphs_item|grid_of_cards|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_cards';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Component',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Component',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_info|paragraphs_item|grid_of_cards|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_theme|paragraphs_item|grid_of_cards|form';
  $field_group->group_name = 'group_theme';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_cards';
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
      'label' => 'Theme',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-theme field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_theme|paragraphs_item|grid_of_cards|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cards');
  t('Component');
  t('Theme');

  return $field_groups;
}
