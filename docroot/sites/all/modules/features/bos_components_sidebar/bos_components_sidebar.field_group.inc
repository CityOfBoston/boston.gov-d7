<?php
/**
 * @file
 * bos_components_sidebar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_components_sidebar_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar_item_w_icon|paragraphs_item|sidebar_item_w_icon|form';
  $field_group->group_name = 'group_sidebar_item_w_icon';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'sidebar_item_w_icon';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar Item w/ Icon',
    'weight' => '0',
    'children' => array(
      0 => 'field_sidebar_icon',
      1 => 'field_sidebar_text',
      2 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sidebar Item w/ Icon',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_sidebar_item_w_icon|paragraphs_item|sidebar_item_w_icon|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar_item|paragraphs_item|sidebar_item|form';
  $field_group->group_name = 'group_sidebar_item';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'sidebar_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar Item',
    'weight' => '0',
    'children' => array(
      0 => 'field_sidebar_text',
      1 => 'field_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sidebar Item',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_sidebar_item|paragraphs_item|sidebar_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_links|paragraphs_item|social_media_links|form';
  $field_group->group_name = 'group_social_media_links';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'social_media_links';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media Links',
    'weight' => '0',
    'children' => array(
      0 => 'field_social_media_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Media Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_social_media_links|paragraphs_item|social_media_links|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_network_info|paragraphs_item|social_networking|form';
  $field_group->group_name = 'group_social_network_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'social_networking';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Networking Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_external_link',
      1 => 'field_social_icon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Networking Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_social_network_info|paragraphs_item|social_networking|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sidebar Item');
  t('Sidebar Item w/ Icon');
  t('Social Media Links');
  t('Social Networking Info');

  return $field_groups;
}
