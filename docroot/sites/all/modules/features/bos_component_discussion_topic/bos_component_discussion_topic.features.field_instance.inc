<?php
/**
 * @file
 * bos_component_discussion_topic.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_discussion_topic_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-discussion_topic-field_description'.
  $field_instances['paragraphs_item-discussion_topic-field_description'] = array(
    'bundle' => 'discussion_topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The details for this discussion topic.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 10,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-discussion_topic-field_links'.
  $field_instances['paragraphs_item-discussion_topic-field_links'] = array(
    'bundle' => 'discussion_topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Resources for this discussion topic',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_links',
    'label' => 'Resources',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'city_score_dashboard' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'discussion_topic' => -1,
        'document' => 'document',
        'drawer' => -1,
        'drawers' => -1,
        'election_results' => -1,
        'external_link' => 'external_link',
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'fyi' => -1,
        'gol_list_links' => -1,
        'grid_of_people' => -1,
        'grid_of_places' => -1,
        'grid_of_programs_initiatives' => -1,
        'grid_of_quotes' => -1,
        'grid_of_topics' => -1,
        'group_of_links_grid' => -1,
        'group_of_links_list' => -1,
        'group_of_links_mini_grid' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'iframe' => -1,
        'internal_link' => 'internal_link',
        'list' => -1,
        'message_for_the_day' => -1,
        'news_announcements' => -1,
        'photo' => -1,
        'quote' => -1,
        'recollect_widget' => -1,
        'script_embed' => -1,
        'seamless_doc' => -1,
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => -1,
        'status_override' => -1,
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
        'upcoming_events' => -1,
        'user_action' => -1,
        'video' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'bos311' => 3,
        'cabinet' => 4,
        'city_score_dashboard' => 5,
        'custom_hours_text' => 6,
        'daily_hours' => 7,
        'discussion_topic' => 8,
        'document' => 9,
        'drawer' => 10,
        'drawers' => 11,
        'election_results' => 12,
        'external_link' => 13,
        'featured_item' => 14,
        'featured_topics' => 15,
        'feedback' => 16,
        'fyi' => 17,
        'gol_list_links' => 18,
        'grid_of_people' => 19,
        'grid_of_places' => 20,
        'grid_of_programs_initiatives' => 21,
        'grid_of_quotes' => 22,
        'grid_of_topics' => 23,
        'group_of_links_grid' => 24,
        'group_of_links_list' => 25,
        'group_of_links_mini_grid' => 26,
        'header_text' => 27,
        'hero_image' => 28,
        'how_to_contact_step' => 29,
        'how_to_tab' => 30,
        'how_to_text_step' => 31,
        'iframe' => 32,
        'internal_link' => 33,
        'list' => 34,
        'message_for_the_day' => 35,
        'news_announcements' => 36,
        'photo' => 37,
        'quote' => 38,
        'recollect_widget' => 39,
        'script_embed' => 40,
        'seamless_doc' => 41,
        'sidebar_item' => 42,
        'sidebar_item_w_icon' => 43,
        'social_media_links' => 44,
        'social_networking' => 45,
        'status_override' => 46,
        'text' => 47,
        'text_one_column' => 48,
        'text_three_column' => 49,
        'text_two_column' => 50,
        'transaction_grid' => 51,
        'upcoming_events' => 52,
        'user_action' => 53,
        'video' => 54,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Resource',
      'title_multiple' => 'Resources',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-discussion_topic-field_title'.
  $field_instances['paragraphs_item-discussion_topic-field_title'] = array(
    'bundle' => 'discussion_topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_title',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => 0,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Resources');
  t('Resources for this discussion topic');
  t('The details for this discussion topic.');
  t('Title');

  return $field_instances;
}
