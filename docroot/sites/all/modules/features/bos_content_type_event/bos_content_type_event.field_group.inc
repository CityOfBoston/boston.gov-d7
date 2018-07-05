<?php
/**
 * @file
 * bos_content_type_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cancelled|node|event|form';
  $field_group->group_name = 'group_cancelled';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_details';
  $field_group->data = [
    'label' => 'Cancel Event',
    'weight' => '44',
    'children' => [
      0 => 'field_cancel_event',
      1 => 'field_extra_info_event',
    ],
    'format_type' => 'fieldset',
    'format_settings' => [
      'formatter' => 'collapsible',
      'instance_settings' => [
        'description' => '',
        'classes' => 'group-cancelled field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ],
    ],
  ];
  $field_groups['group_cancelled|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_components|node|event|form';
  $field_group->group_name = 'group_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Components',
    'weight' => '8',
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
  $field_groups['group_components|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_basic_info|node|event|form';
  $field_group->group_name = 'group_event_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_featured',
      1 => 'field_thumbnail',
      2 => 'body',
      3 => 'field_intro_image',
      4 => 'field_intro_text',
      5 => 'field_contact',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-event-basic-info field-group-tab',
        'description' => '<p><a href="https://docs.google.com/document/d/1e3hyjdqM9W8M6WQ-VfuBJKy4dJOrp4XwAwqIcek31Hs/edit" target="_blank">Here\'s some tips for creating an event.</a></p>
',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_event_basic_info|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_dates|node|event|form';
  $field_group->group_name = 'group_event_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Dates',
    'weight' => '4',
    'children' => array(
      0 => 'field_event_dates',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-dates field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_dates|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_details|node|event|form';
  $field_group->group_name = 'group_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_event_contact',
      1 => 'field_phone_number',
      2 => 'field_email',
      3 => 'group_cancelled',
      4 => 'group_event_information',
      5 => 'group_event_location',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_details|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_information|node|event|form';
  $field_group->group_name = 'group_event_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_details';
  $field_group->data = array(
    'label' => 'Event Information',
    'weight' => '45',
    'children' => array(
      0 => 'field_cost',
      1 => 'field_details_link',
      2 => 'field_links',
      3 => 'field_event_type',
      4 => 'field_multiple_neighborhoods',
      5 => 'field_city_sponsored',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Event Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-event-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_event_information|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_location|node|event|form';
  $field_group->group_name = 'group_event_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_details';
  $field_group->data = array(
    'label' => 'Event Location',
    'weight' => '43',
    'children' => array(
      0 => 'field_address',
      1 => 'field_city_hall',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-location field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_event_location|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_metadata|node|event|form';
  $field_group->group_name = 'group_page_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Meta Data',
    'weight' => '6',
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
  $field_groups['group_page_metadata|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|event|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Content',
    'weight' => '9',
    'children' => array(
      0 => 'field_place',
      1 => 'field_program_initiative',
      2 => 'field_people',
      3 => 'field_related_content',
      4 => 'field_related_events_notices',
      5 => 'field_related_guides',
      6 => 'field_related_posts',
      7 => 'field_related_departments',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_content|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar_components|node|event|form';
  $field_group->group_name = 'group_sidebar_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar Components',
    'weight' => '7',
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
  $field_groups['group_sidebar_components|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Information');
  t('Cancel Event');
  t('Components');
  t('Event Dates');
  t('Event Details');
  t('Event Information');
  t('Event Location');
  t('Page Meta Data');
  t('Related Content');
  t('Sidebar Components');

  return $field_groups;
}
