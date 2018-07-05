<?php
/**
 * @file
 * bos_components_commissions.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_components_commissions_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_commission_contact_info_info|paragraphs_item|commission_contact_info|form';
  $field_group->group_name = 'group_commission_contact_info_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'commission_contact_info';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commission Contact Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_commission',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-commission-contact-info-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_commission_contact_info_info|paragraphs_item|commission_contact_info|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_commission_members_info|paragraphs_item|commission_members|form';
  $field_group->group_name = 'group_commission_members_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'commission_members';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commission Members',
    'weight' => '0',
    'children' => array(
      0 => 'field_commission',
      1 => 'field_component_title',
      2 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-commission-members-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_commission_members_info|paragraphs_item|commission_members|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_commission_summary_info|paragraphs_item|commission_summary|form';
  $field_group->group_name = 'group_commission_summary_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'commission_summary';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commission Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_commission',
      1 => 'field_component_title',
      2 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-commission-summary-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_commission_summary_info|paragraphs_item|commission_summary|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Commission Contact Info');
  t('Commission Info');
  t('Commission Members');

  return $field_groups;
}
