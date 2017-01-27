<?php
/**
 * @file
 * bos_component_card.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_card_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_info|paragraphs_item|card|form';
  $field_group->group_name = 'group_card_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'card';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Card Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_title',
      1 => 'field_link',
      2 => 'field_image',
      3 => 'field_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-card-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Card Info');

  return $field_groups;
}
