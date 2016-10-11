<?php
/**
 * @file
 * bos_component_script_embed.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_script_embed_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_script_info|paragraphs_item|script_embed|form';
  $field_group->group_name = 'group_script_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'script_embed';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Script Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_source_url',
      1 => 'field_sticky',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Script Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-script-info field-group-tabs',
      ),
    ),
  );
  $field_groups['group_script_info|paragraphs_item|script_embed|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Script Information');

  return $field_groups;
}
