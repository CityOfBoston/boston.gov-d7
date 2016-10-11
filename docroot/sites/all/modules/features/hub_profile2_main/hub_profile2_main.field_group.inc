<?php
/**
 * @file
 * hub_profile2_main.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hub_profile2_main_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editable_information|profile2|main|form';
  $field_group->group_name = 'group_editable_information';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editable Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_linked_in',
      1 => 'field_twitter',
      2 => 'field_user_picture',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-editable-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_editable_information|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_emergency_contact|profile2|main|form';
  $field_group->group_name = 'group_emergency_contact';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_private_information';
  $field_group->data = array(
    'label' => 'Emergency Contact',
    'weight' => '17',
    'children' => array(
      0 => 'field_emergency_contact_name',
      1 => 'field_emergency_contact_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-emergency-contact field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_emergency_contact|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_private_information|profile2|main|form';
  $field_group->group_name = 'group_private_information';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Private Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_home_address',
      1 => 'field_mailing_address',
      2 => 'field_personal_email',
      3 => 'field_phone_number',
      4 => 'group_emergency_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-private-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_private_information|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_public_information|profile2|main|form';
  $field_group->group_name = 'group_public_information';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Public Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_display_name',
      2 => 'field_office_location',
      3 => 'field_position_title',
      4 => 'field_work_email',
      5 => 'field_work_phone_number',
      6 => 'field_manager',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-public-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_public_information|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system_information|profile2|main|form';
  $field_group->group_name = 'group_system_information';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-system-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_system_information|profile2|main|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editable Information');
  t('Emergency Contact');
  t('Private Information');
  t('Public Information');
  t('System Information');

  return $field_groups;
}
