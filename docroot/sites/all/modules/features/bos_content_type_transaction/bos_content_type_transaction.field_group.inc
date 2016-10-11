<?php
/**
 * @file
 * bos_content_type_transaction.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_transaction_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|node|transaction|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'transaction';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_link',
      2 => 'title',
      3 => 'field_sticky',
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
  $field_groups['group_basic_information|node|transaction|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Information');

  return $field_groups;
}
