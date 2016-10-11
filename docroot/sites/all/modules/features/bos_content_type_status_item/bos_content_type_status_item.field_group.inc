<?php
/**
 * @file
 * bos_content_type_status_item.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_status_item_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|node|status_item|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'status_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_title',
      1 => 'field_icon',
      2 => 'field_alert_icon',
      3 => 'title',
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
  $field_groups['group_basic_information|node|status_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_messages|node|status_item|form';
  $field_group->group_name = 'group_messages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'status_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Messages',
    'weight' => '1',
    'children' => array(
      0 => 'field_messages',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-messages field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_messages|node|status_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_message|paragraphs_item|message_for_the_day|form';
  $field_group->group_name = 'group_message';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'message_for_the_day';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Message',
    'weight' => '0',
    'children' => array(
      0 => 'field_date',
      1 => 'field_link',
      2 => 'field_message',
      3 => 'field_use_alert',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Message',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-message field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_message|paragraphs_item|message_for_the_day|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Information');
  t('Message');
  t('Messages');

  return $field_groups;
}
