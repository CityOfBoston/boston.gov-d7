<?php
/**
 * @file
 * bos_content_type_public_notice.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_public_notice_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|public_notice|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_contact',
      2 => 'field_featured',
      3 => 'field_intro_text',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basic|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cancelled|node|public_notice|form';
  $field_group->group_name = 'group_cancelled';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Cancel Public Notice',
    'weight' => '16',
    'children' => array(
      0 => 'field_cancelled',
      1 => 'field_extra_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cancelled field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cancelled|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_components|node|public_notice|form';
  $field_group->group_name = 'group_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
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
  $field_groups['group_components|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info|node|public_notice|form';
  $field_group->group_name = 'group_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_email',
      1 => 'field_event_contact',
      2 => 'field_phone_number',
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
  $field_groups['group_contact_info|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|public_notice|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_address',
      1 => 'field_public_notice_date',
      2 => 'field_live_stream',
      3 => 'group_cancelled',
      4 => 'group_downloads',
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
  $field_groups['group_details|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_downloads|node|public_notice|form';
  $field_group->group_name = 'group_downloads';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Downloads',
    'weight' => '17',
    'children' => array(
      0 => 'field_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-downloads field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_downloads|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|public_notice|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Items',
    'weight' => '5',
    'children' => array(
      0 => 'field_contacts',
      1 => 'field_multiple_neighborhoods',
      2 => 'field_related_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related|node|public_notice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics|node|public_notice|form';
  $field_group->group_name = 'group_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'public_notice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add Discussion Topics',
    'weight' => '3',
    'children' => array(
      0 => 'field_drawer',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-topics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_topics|node|public_notice|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Discussion Topics');
  t('Basic Information');
  t('Cancel Public Notice');
  t('Components');
  t('Contact Information');
  t('Details');
  t('Downloads');
  t('Related Items');

  return $field_groups;
}
