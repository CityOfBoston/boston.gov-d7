<?php
/**
 * @file
 * bos_component_grid_of_cards.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_grid_of_cards_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cards_info|paragraphs_item|grid_of_cards|form';
  $field_group->group_name = 'group_cards_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'grid_of_cards';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cards Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_title',
      1 => 'field_short_title',
      2 => 'field_contacts',
      3 => 'field_children',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cards-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cards Info');

  return $field_groups;
}
