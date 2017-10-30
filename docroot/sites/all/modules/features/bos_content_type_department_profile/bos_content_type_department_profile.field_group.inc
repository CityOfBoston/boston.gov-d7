<?php
/**
 * @file
 * bos_content_type_department_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_department_profile_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alternative_display|node|department_profile|form';
  $field_group->group_name = 'group_alternative_display';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Alternative Display',
    'weight' => '2',
    'children' => array(
      0 => 'field_icon',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-alternative-display field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_alternative_display|node|department_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|node|department_profile|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_intro_text',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basic_information|node|department_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_components|node|department_profile|form';
  $field_group->group_name = 'group_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Components',
    'weight' => '4',
    'children' => array(
      0 => 'field_components',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-components field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_components|node|department_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_information|node|department_profile|form';
  $field_group->group_name = 'group_contact_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_email',
      1 => 'field_operation_hours',
      2 => 'field_phone_number',
      3 => 'field_address',
      4 => 'field_department_type',
      5 => 'field_hide_contact_form',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact_information|node|department_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_metadata|node|department_profile|form';
  $field_group->group_name = 'group_page_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_published_date',
      1 => 'field_updated_date',
      2 => 'field_type_of_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_metadata|node|department_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar_components|node|department_profile|form';
  $field_group->group_name = 'group_sidebar_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar Components',
    'weight' => '5',
    'children' => array(
      0 => 'field_sidebar_components',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_sidebar_components|node|department_profile|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternative Display');
  t('Basic Information');
  t('Components');
  t('Contact Information');
  t('Page Metadata');
  t('Sidebar Components');

  return $field_groups;
}
