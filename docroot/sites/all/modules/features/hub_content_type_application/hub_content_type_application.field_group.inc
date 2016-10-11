<?php
/**
 * @file
 * hub_content_type_application.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hub_content_type_application_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_info|node|application|form';
  $field_group->group_name = 'group_app_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_application_id',
      1 => 'field_external_link',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_app_info|node|application|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Application Information');

  return $field_groups;
}
