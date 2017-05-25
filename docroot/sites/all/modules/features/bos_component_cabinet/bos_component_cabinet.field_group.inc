<?php
/**
 * @file
 * bos_component_cabinet.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_cabinet_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contacts|paragraphs_item|cabinet|form';
  $field_group->group_name = 'group_contacts';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'cabinet';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '1',
    'children' => array(
      0 => 'field_contacts',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contacts',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_contacts|paragraphs_item|cabinet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|paragraphs_item|cabinet|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'cabinet';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_person',
      2 => 'field_title',
      3 => 'field_short_title',
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
  $field_groups['group_details|paragraphs_item|cabinet|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  t('Details');

  return $field_groups;
}
