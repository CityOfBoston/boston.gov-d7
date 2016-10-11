<?php
/**
 * @file
 * bos_component_featured_item.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_featured_item_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|paragraphs_item|featured_item|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Item Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_featured_item',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Item Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-basic-information field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_basic_information|paragraphs_item|featured_item|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Item Info');

  return $field_groups;
}
