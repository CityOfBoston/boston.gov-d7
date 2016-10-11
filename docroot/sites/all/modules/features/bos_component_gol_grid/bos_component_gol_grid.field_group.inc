<?php
/**
 * @file
 * bos_component_gol_grid.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_gol_grid_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_information|paragraphs_item|group_of_links_grid|form';
  $field_group->group_name = 'group_basic_information';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'group_of_links_grid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_contact',
      2 => 'field_description',
      3 => 'field_short_title',
      4 => 'field_subheader',
      5 => 'field_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Link Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_basic_information|paragraphs_item|group_of_links_grid|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_field_grid_links_link|field_collection_item|field_grid_links|form';
  $field_group->group_name = 'group_field_grid_links_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_grid_links';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '0',
    'children' => array(
      0 => 'field_extra_info',
      1 => 'field_grid_link',
      2 => 'field_short_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Link',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-field-grid-links-link field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_field_grid_links_link|field_collection_item|field_grid_links|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|paragraphs_item|group_of_links_grid|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'group_of_links_grid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_grid_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_links|paragraphs_item|group_of_links_grid|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Link');
  t('Link Details');
  t('Links');

  return $field_groups;
}
