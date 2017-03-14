<?php
/**
 * @file
 * bos_content_type_site_alert.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_site_alert_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|site_alert|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site_alert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_icon',
      1 => 'field_extra_info',
      2 => 'field_link',
      3 => 'title_field',
      4 => 'field_theme',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_info|node|site_alert|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Info');

  return $field_groups;
}
