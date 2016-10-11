<?php
/**
 * @file
 * bos_component_text.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_text_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|paragraphs_item|text|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_background_image',
      1 => 'field_component_title',
      2 => 'field_contact',
      3 => 'field_hide_title_bar',
      4 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Text Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_basic_information|paragraphs_item|text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_blocks|paragraphs_item|text|form';
  $field_group->group_name = 'group_text_blocks';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Blocks',
    'weight' => '6',
    'children' => array(
      0 => 'field_text_blocks',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Text Blocks',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_text_blocks|paragraphs_item|text|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Text Blocks');
  t('Text Information');

  return $field_groups;
}
