<?php
/**
 * @file
 * bos_component_upcoming_events.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_upcoming_events_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-upcoming_events-field_component_title'
  $field_instances['paragraphs_item-upcoming_events-field_component_title'] = array(
    'bundle' => 'upcoming_events',
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
    'field_name' => 'field_component_title',
    'label' => 'Title',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-upcoming_events-field_featured_item'
  $field_instances['paragraphs_item-upcoming_events-field_featured_item'] = array(
    'bundle' => 'upcoming_events',
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
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_featured_item',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-upcoming_events-field_link'
  $field_instances['paragraphs_item-upcoming_events-field_link'] = array(
    'bundle' => 'upcoming_events',
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
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_link',
    'label' => 'Events Page Link',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'cabinet' => -1,
        'city_score_dashboard' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => -1,
        'external_link' => 'external_link',
        'featured_item' => -1,
        'featured_topics' => -1,
        'fyi' => -1,
        'gol_list_links' => -1,
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
        'news_announcements' => -1,
        'photo' => -1,
        'quote' => -1,
        'recollect_widget' => -1,
        'seamless_doc' => -1,
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => -1,
        'tabbed_content_tab' => -1,
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
        'cabinet' => 3,
        'city_score_dashboard' => 4,
        'document' => 5,
        'drawer' => 6,
        'drawers' => 7,
        'external_link' => 8,
        'featured_item' => 9,
        'featured_topics' => 10,
        'fyi' => 11,
        'gol_list_links' => 12,
        'grid_of_quotes' => 13,
        'grid_of_topics' => 14,
        'group_of_links_grid' => 15,
        'group_of_links_list' => 16,
        'group_of_links_mini_grid' => 17,
        'header_text' => 18,
        'hero_image' => 19,
        'how_to_contact_step' => 20,
        'how_to_tab' => 21,
        'how_to_text_step' => 22,
        'iframe' => 23,
        'internal_link' => 24,
        'list' => 25,
        'news_announcements' => 26,
        'photo' => 27,
        'quote' => 28,
        'recollect_widget' => 29,
        'seamless_doc' => 30,
        'sidebar_item' => 31,
        'sidebar_item_w_icon' => 32,
        'social_media_links' => 33,
        'social_networking' => 34,
        'tabbed_content_tab' => 35,
        'text' => 36,
        'text_one_column' => 37,
        'text_three_column' => 38,
        'text_two_column' => 39,
        'transaction_grid' => 40,
        'upcoming_events' => 41,
        'user_action' => 42,
        'video' => 43,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-upcoming_events-field_list'
  $field_instances['paragraphs_item-upcoming_events-field_list'] = array(
    'bundle' => 'upcoming_events',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_list',
    'label' => 'List',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'admin_views_comment' => 0,
        'admin_views_file' => 0,
        'admin_views_node' => 0,
        'admin_views_user' => 0,
        'api_public_notice' => 0,
        'blank_layouts' => 0,
        'bos_department_listing' => 0,
        'bos_news_landing' => 0,
        'boston_current_user' => 0,
        'boston_departments' => 0,
        'boston_edits_by_user' => 0,
        'boston_emergencies' => 0,
        'boston_events' => 0,
        'boston_media_browser_tabs' => 0,
        'boston_moderation_content' => 0,
        'boston_posts' => 0,
        'boston_recent_content' => 0,
        'boston_scheduling' => 0,
        'boston_scheduling_event' => 0,
        'boston_scheduling_post' => 0,
        'boston_site_alerts' => 0,
        'calendar' => 0,
        'change_log' => 0,
        'feed_departments' => 0,
        'feed_events' => 0,
        'media_default' => 0,
        'metrolist_affordable_housing' => 0,
        'news_announcements' => 0,
        'places' => 0,
        'program_initiatives' => 0,
        'public_notice' => 0,
        'related_content_migration' => 0,
        'related_events' => 'related_events',
        'rss_news' => 0,
        'site_alert' => 0,
        'status_displays' => 0,
        'topic_landing_page' => 0,
        'transactions' => 0,
        'upcoming_events' => 'upcoming_events',
        'upcoming_events_feed' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-upcoming_events-field_short_title'
  $field_instances['paragraphs_item-upcoming_events-field_short_title'] = array(
    'bundle' => 'upcoming_events',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Events Page Link');
  t('Featured Item');
  t('List');
  t('Short Title');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('Title');

  return $field_instances;
}
