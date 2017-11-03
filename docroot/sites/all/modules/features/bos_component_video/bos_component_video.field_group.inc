<?php
/**
 * @file
 * bos_component_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_video_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_info|paragraphs_item|video|form';
  $field_group->group_name = 'group_video_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_extra_info',
      1 => 'field_image',
      2 => 'field_short_title',
      4 => 'field_contact',
      5 => 'field_is_channel',
      6 => 'field_component_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_video_info|paragraphs_item|video|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Video Info');

  return $field_groups;
}
