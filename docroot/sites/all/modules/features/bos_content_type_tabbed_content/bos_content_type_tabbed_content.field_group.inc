<?php
/**
 * @file
 * bos_content_type_tabbed_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_content_type_tabbed_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|node|tabbed_content|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tabbed_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_intro_image',
      1 => 'field_intro_text',
      2 => 'title',
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
  $field_groups['group_basic_information|node|tabbed_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_metadata|node|tabbed_content|form';
  $field_group->group_name = 'group_page_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tabbed_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_type_of_content',
      1 => 'field_published_date',
      2 => 'field_updated_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_metadata|node|tabbed_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_info|paragraphs_item|tabbed_content_tab|form';
  $field_group->group_name = 'group_tab_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'tabbed_content_tab';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab',
    'weight' => '0',
    'children' => array(
      0 => 'field_components',
      1 => 'field_component_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tab',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-tab-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_tab_info|paragraphs_item|tabbed_content_tab|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|tabbed_content|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tabbed_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '2',
    'children' => array(
      0 => 'field_tabbed_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tabs field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_tabs|node|tabbed_content|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Information');
  t('Page Metadata');
  t('Tab');
  t('Tabs');

  return $field_groups;
}
