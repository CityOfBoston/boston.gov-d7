<?php
/**
 * @file
 * bos_component_grid_of_topics.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_grid_of_topics_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_grid_of_topics_info|paragraphs_item|grid_of_topics|form';
  $field_group->group_name = 'group_grid_of_topics_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Grid of Guides Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Grid of Guides Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_grid_of_topics_info|paragraphs_item|grid_of_topics|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics|paragraphs_item|grid_of_topics|form';
  $field_group->group_name = 'group_topics';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Guides',
    'weight' => '1',
    'children' => array(
      0 => 'field_topics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Guides',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_topics|paragraphs_item|grid_of_topics|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Grid of Guides Information');
  t('Guides');

  return $field_groups;
}
