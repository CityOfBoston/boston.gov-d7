<?php
/**
 * @file
 * bos_component_events_and_notices.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_events_and_notices_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_and_notices|paragraphs_item|events_and_notices|form';
  $field_group->group_name = 'group_events_and_notices';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'events_and_notices';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events & Notices',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_short_title',
      2 => 'field_featured_item',
      3 => 'field_list',
      4 => 'field_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-events-and-notices field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_events_and_notices|paragraphs_item|events_and_notices|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events & Notices');

  return $field_groups;
}
