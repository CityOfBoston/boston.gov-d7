<?php
/**
 * @file
 * bos_component_featured_topics.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_featured_topics_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_topics_list|paragraphs_item|featured_topics|form';
  $field_group->group_name = 'group_featured_topics_list';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'featured_topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured Guides List',
    'weight' => '4',
    'children' => array(
      0 => 'field_topics',
      1 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured Guides List',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-featured-topics-list field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_featured_topics_list|paragraphs_item|featured_topics|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Featured Guides List');

  return $field_groups;
}
