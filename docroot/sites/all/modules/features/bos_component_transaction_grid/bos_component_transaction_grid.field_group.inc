<?php
/**
 * @file
 * bos_component_transaction_grid.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_transaction_grid_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_transaction_info|paragraphs_item|transaction_grid|form';
  $field_group->group_name = 'group_transaction_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'transaction_grid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Transaction Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_short_title',
      3 => 'field_transactions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Transaction Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-transaction-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_transaction_info|paragraphs_item|transaction_grid|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Transaction Info');

  return $field_groups;
}
