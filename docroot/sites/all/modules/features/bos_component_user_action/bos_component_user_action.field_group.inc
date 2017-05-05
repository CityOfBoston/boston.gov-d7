<?php
/**
 * @file
 * bos_component_user_action.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_user_action_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_action_info|paragraphs_item|user_action|form';
  $field_group->group_name = 'group_user_action_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'user_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Action Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
      1 => 'field_intro_text',
      2 => 'field_links',
      3 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-action-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_user_action_info|paragraphs_item|user_action|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('User Action Info');

  return $field_groups;
}
