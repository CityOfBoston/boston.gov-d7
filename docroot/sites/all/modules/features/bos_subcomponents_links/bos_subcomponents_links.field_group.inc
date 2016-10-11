<?php
/**
 * @file
 * bos_subcomponents_links.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_subcomponents_links_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link_info|paragraphs_item|document|form';
  $field_group->group_name = 'group_link_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_document',
      1 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-link-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_link_info|paragraphs_item|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link_info|paragraphs_item|external_link|form';
  $field_group->group_name = 'group_link_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'external_link';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_external_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-link-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_link_info|paragraphs_item|external_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link_info|paragraphs_item|internal_link|form';
  $field_group->group_name = 'group_link_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'internal_link';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_internal_link',
      1 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-link-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_link_info|paragraphs_item|internal_link|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Link Info');

  return $field_groups;
}
