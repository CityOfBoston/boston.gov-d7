<?php
/**
 * @file
 * bos_component_feedback.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_feedback_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feedback_info|paragraphs_item|feedback|form';
  $field_group->group_name = 'group_feedback_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Feedback Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_poll',
      2 => 'field_question',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Feedback Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-feedback-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_feedback_info|paragraphs_item|feedback|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Feedback Info');

  return $field_groups;
}
