<?php
/**
 * @file
 * bos_component_newsletter.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_newsletter_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_newsletter|paragraphs_item|newsletter|form';
  $field_group->group_name = 'group_newsletter';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'newsletter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Newsletter',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_theme',
      1 => 'field_component_title',
      2 => 'field_contact',
      3 => 'field_description',
      4 => 'field_newsletter',
      5 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Newsletter',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-newsletter field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_newsletter|paragraphs_item|newsletter|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Newsletter');

  return $field_groups;
}
