<?php
/**
 * @file
 * bos_component_iframe.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_iframe_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_iframe_info|paragraphs_item|iframe|form';
  $field_group->group_name = 'group_iframe_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Iframe Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_source_url',
      1 => 'field_component_title',
      2 => 'field_contact',
      3 => 'field_iframe_size',
      4 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Iframe Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-iframe-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_iframe_info|paragraphs_item|iframe|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Iframe Info');

  return $field_groups;
}
