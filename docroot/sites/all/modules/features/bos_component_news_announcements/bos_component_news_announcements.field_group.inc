<?php
/**
 * @file
 * bos_component_news_announcements.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bos_component_news_announcements_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_announcements|paragraphs_item|news_announcements|form';
  $field_group->group_name = 'group_news_announcements';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'news_announcements';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'News & Announcements',
    'weight' => '1',
    'children' => array(
      0 => 'field_component_title',
      1 => 'field_featured_post',
      2 => 'field_list',
      3 => 'field_link',
      4 => 'field_short_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'News & Announcements',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-news-announcements field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_news_announcements|paragraphs_item|news_announcements|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('News & Announcements');

  return $field_groups;
}
