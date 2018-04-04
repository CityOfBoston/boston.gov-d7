<?php
/**
 * @file
 * bos_component_list.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_list_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-list-field_component_theme'.
  $field_instances['paragraphs_item-list-field_component_theme'] = array(
    'bundle' => 'list',
    'default_value' => array(
      0 => array(
        'value' => 'w',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_component_theme',
    'label' => 'Component Theme',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-list-field_component_title'.
  $field_instances['paragraphs_item-list-field_component_title'] = array(
    'bundle' => 'list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => FALSE,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-list-field_contact'.
  $field_instances['paragraphs_item-list-field_contact'] = array(
    'bundle' => 'list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The contact associated with this list component.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'contact',
        ),
        'type' => 'entityreference_entity_view',
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
    'field_name' => 'field_contact',
    'label' => 'Contact',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => 0,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-list-field_list'.
  $field_instances['paragraphs_item-list-field_list'] = array(
    'bundle' => 'list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a list to this component.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
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
    'field_name' => 'field_list',
    'label' => 'List',
    'required' => 1,
    'settings' => array(
      'allowed_views' => array(
        'admin_views_comment' => 0,
        'admin_views_file' => 0,
        'admin_views_node' => 0,
        'admin_views_user' => 0,
        'api_public_notice' => 0,
        'bids_rfps' => 'bids_rfps',
        'blank_layouts' => 0,
        'bos_department_listing' => 'bos_department_listing',
        'bos_news_landing' => 'bos_news_landing',
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
        'calendar' => 'calendar',
        'change_log' => 0,
        'feed_departments' => 0,
        'feed_events' => 0,
        'hub_list_applications' => 'hub_list_applications',
        'media_default' => 0,
        'metrolist_affordable_housing' => 'metrolist_affordable_housing',
        'news_announcements' => 0,
        'places' => 'places',
        'program_initiatives' => 0,
        'public_notice' => 'public_notice',
        'related_events' => 0,
        'rss_news' => 0,
        'site_alert' => 0,
        'status_displays' => 'status_displays',
        'topic_landing_page' => 'topic_landing_page',
        'transactions' => 'transactions',
        'upcoming_events' => 0,
        'upcoming_events_featured_event_filter' => 0,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-list-field_short_title'.
  $field_instances['paragraphs_item-list-field_short_title'] = array(
    'bundle' => 'list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a list to this component.');
  t('Component Theme');
  t('Contact');
  t('List');
  t('Short Title');
  t('The contact associated with this list component.');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('Title');

  return $field_instances;
}
