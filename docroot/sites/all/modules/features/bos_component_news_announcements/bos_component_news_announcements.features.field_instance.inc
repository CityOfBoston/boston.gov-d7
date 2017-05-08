<?php
/**
 * @file
 * bos_component_news_announcements.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_news_announcements_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-news_announcements-field_component_title'
  $field_instances['paragraphs_item-news_announcements-field_component_title'] = array(
    'bundle' => 'news_announcements',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please provide a title for this component. The title will be displayed across the top of the component.',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_component_title',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-news_announcements-field_featured_post'
  $field_instances['paragraphs_item-news_announcements-field_featured_post'] = array(
    'bundle' => 'news_announcements',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'view_mode' => 'featured_item',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_featured_post',
    'label' => 'Featured Item',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => array(
          'active' => 0,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-news_announcements-field_link'
  $field_instances['paragraphs_item-news_announcements-field_link'] = array(
    'bundle' => 'news_announcements',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_link',
    'label' => 'News Page Link',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'city_score_dashboard' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => -1,
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
        'user_action' => -1,
        'video' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'bos311' => 3,
        'cabinet' => 4,
        'city_score_dashboard' => 49,
        'custom_hours_text' => 5,
        'daily_hours' => 6,
        'document' => 7,
        'drawer' => 8,
        'drawers' => 9,
        'external_link' => 10,
        'featured_item' => 11,
        'featured_topics' => 12,
        'feedback' => 13,
        'fyi' => 14,
        'gol_list_links' => 15,
        'grid_of_people' => 16,
        'grid_of_places' => 17,
        'grid_of_programs_initiatives' => 18,
        'grid_of_quotes' => 64,
        'grid_of_topics' => 19,
        'group_of_links_grid' => 20,
        'group_of_links_list' => 21,
        'group_of_links_mini_grid' => 22,
        'header_text' => 23,
        'hero_image' => 24,
        'how_to_contact_step' => 25,
        'how_to_tab' => 26,
        'how_to_text_step' => 27,
        'iframe' => 28,
        'internal_link' => 29,
        'list' => 30,
        'message_for_the_day' => 31,
        'news_announcements' => 32,
        'photo' => 33,
        'quote' => 80,
        'sidebar_item' => 34,
        'sidebar_item_w_icon' => 35,
        'social_media_links' => 36,
        'social_networking' => 37,
        'status_override' => 85,
        'text' => 38,
        'text_one_column' => 39,
        'text_three_column' => 40,
        'text_two_column' => 41,
        'transaction_grid' => 42,
        'user_action' => 43,
        'video' => 44,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Link',
      'title_multiple' => 'Links',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'paragraphs_item-news_announcements-field_list'
  $field_instances['paragraphs_item-news_announcements-field_list'] = array(
    'bundle' => 'news_announcements',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a list to this component.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_list',
    'label' => 'List',
    'required' => 1,
    'settings' => array(
      'allowed_views' => array(
        'bos_department_listing' => 0,
        'bos_news_landing' => 0,
        'boston_current_user' => 0,
        'boston_edits_by_user' => 0,
        'boston_moderation_content' => 0,
        'boston_recent_content' => 0,
        'calendar' => 0,
        'media_default' => 0,
        'news_announcements' => 'news_announcements',
        'places' => 0,
        'program_initiatives' => 0,
        'topic_landing_page' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'paragraphs_item-news_announcements-field_short_title'
  $field_instances['paragraphs_item-news_announcements-field_short_title'] = array(
    'bundle' => 'news_announcements',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_short_title',
    'label' => 'Short Title',
    'required' => 0,
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
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a list to this component.');
  t('Featured Item');
  t('List');
  t('News Page Link');
  t('Please provide a title for this component. The title will be displayed across the top of the component.');
  t('Short Title');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('Title');

  return $field_instances;
}
