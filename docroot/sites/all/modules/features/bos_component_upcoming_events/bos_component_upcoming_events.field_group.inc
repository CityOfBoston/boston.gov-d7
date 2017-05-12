<?php
/**
 * @file
 * bos_component_upcoming_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_upcoming_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_upcoming_events|paragraphs_item|upcoming_events|form';
  $field_group->group_name = 'group_upcoming_events';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'upcoming_events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Upcoming Events',
    'weight' => '1',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_featured_item',
      2 => 'field_link',
      3 => 'field_list',
      4 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-upcoming-events field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_upcoming_events|paragraphs_item|upcoming_events|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Upcoming Events');

  return $field_groups;
}
