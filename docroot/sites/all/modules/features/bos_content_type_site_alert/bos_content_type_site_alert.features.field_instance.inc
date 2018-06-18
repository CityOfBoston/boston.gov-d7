<?php
/**
 * @file
 * bos_content_type_site_alert.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_content_type_site_alert_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-site_alert-field_excluded_nodes'.
  $field_instances['node-site_alert-field_excluded_nodes'] = array(
    'bundle' => 'site_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you don\'t want this alert to show on a specific page, add them here.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(),
        'type' => 'entityreference_entity_id',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_excluded_nodes',
    'label' => 'Pages to exclude',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-site_alert-field_extra_info'.
  $field_instances['node-site_alert-field_extra_info'] = array(
    'bundle' => 'site_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The main text of the alert.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_extra_info',
    'label' => 'Content',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-site_alert-field_icon'.
  $field_instances['node-site_alert-field_icon'] = array(
    'bundle' => 'site_alert',
    'deleted' => 0,
    'description' => 'This should be an icon with a circle (same ones used for status updates).',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_url_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
          'url_type' => 3,
        ),
        'type' => 'image_url',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_icon',
    'label' => 'Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'svg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'boston_media_browser_tabs--boston_media' => 'boston_media_browser_tabs--boston_media',
          'boston_media_browser_tabs--icons' => 'boston_media_browser_tabs--icons',
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-site_alert-field_link'.
  $field_instances['node-site_alert-field_link'] = array(
    'bundle' => 'site_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A link to either an external site, an internal page, or a document.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'fyi',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_link',
    'label' => 'Call to Action',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'city_score_dashboard' => -1,
        'commission_contact_info' => -1,
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
        'tabbed_content_tab' => 47,
        'text' => 48,
        'text_one_column' => 49,
        'text_three_column' => 50,
        'text_two_column' => 51,
        'transaction_grid' => 52,
        'upcoming_events' => 53,
        'user_action' => 54,
        'video' => 55,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-site_alert-field_theme'.
  $field_instances['node-site_alert-field_theme'] = array(
    'bundle' => 'site_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Site alerts can be red or blue. Pick one.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_theme',
    'label' => 'Theme',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-site_alert-title_field'.
  $field_instances['node-site_alert-title_field'] = array(
    'bundle' => 'site_alert',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the heading of the FYI.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
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
  t('A link to either an external site, an internal page, or a document.');
  t('Call to Action');
  t('Content');
  t('Icon');
  t('If you don\'t want this alert to show on a specific page, add them here.');
  t('Pages to exclude');
  t('Site alerts can be red or blue. Pick one.');
  t('The main text of the alert.');
  t('Theme');
  t('This is the heading of the FYI.');
  t('This should be an icon with a circle (same ones used for status updates).');
  t('Title');

  return $field_instances;
}
