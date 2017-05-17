<?php
/**
 * @file
 * bos_signup_alerts.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_signup_alerts_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component|paragraphs_item|bos_signup_emergency_alerts|form';
  $field_group->group_name = 'group_component';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'bos_signup_emergency_alerts';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Component',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_theme',
      1 => 'field_component_title',
      2 => 'field_contact',
      3 => 'field_description',
      4 => 'field_intro_text',
      5 => 'field_short_title',
      6 => 'field_icon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-component field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_component|paragraphs_item|bos_signup_emergency_alerts|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Component');

  return $field_groups;
}
