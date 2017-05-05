<?php
/**
 * @file
 * bos_component_hero_image.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_hero_image_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero_info|paragraphs_item|hero_image|form';
  $field_group->group_name = 'group_hero_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'hero_image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_grid_link',
      1 => 'field_header',
      2 => 'field_image',
      3 => 'field_intro_text',
      4 => 'field_subheader',
      5 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Hero Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hero-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_hero_info|paragraphs_item|hero_image|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hero Info');

  return $field_groups;
}
