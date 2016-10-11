<?php
/**
 * @file
 * bos_component_photo.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_photo_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_details|paragraphs_item|photo|default';
  $field_group->group_name = 'group_photo_details';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'photo';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photo Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_photo_caption',
      2 => 'field_photo_credit',
      3 => 'field_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Photo Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'photo-details',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_details|paragraphs_item|photo|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_info|paragraphs_item|photo|form';
  $field_group->group_name = 'group_photo_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'photo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photo Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contacts',
      2 => 'field_image',
      3 => 'field_photo_caption',
      4 => 'field_photo_credit',
      5 => 'field_short_title',
      6 => 'field_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Photo Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-photo-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_photo_info|paragraphs_item|photo|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Photo Details');
  t('Photo Info');

  return $field_groups;
}
