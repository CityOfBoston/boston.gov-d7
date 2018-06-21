<?php
/**
 * @file
 * bos_content_type_tabbed_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_content_type_tabbed_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-tabbed_content-field_intro_image'.
  $field_instances['node-tabbed_content-field_intro_image'] = array(
    'bundle' => 'tabbed_content',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_intro_image',
    'label' => 'Intro Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'tabbed-intro-image-[current-date:file_directory_storage_date]',
      'file_extensions' => 'png gif jpg jpeg svg',
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
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-tabbed_content-field_intro_text'.
  $field_instances['node-tabbed_content-field_intro_text'] = array(
    'bundle' => 'tabbed_content',
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_intro_text',
    'label' => 'Intro Text',
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
        'rows' => 5,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-tabbed_content-field_published_date'.
  $field_instances['node-tabbed_content-field_published_date'] = array(
    'bundle' => 'tabbed_content',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_published_date',
    'label' => 'Published Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'site-wide',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-tabbed_content-field_tabbed_content'.
  $field_instances['node-tabbed_content-field_tabbed_content'] = array(
    'bundle' => 'tabbed_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add tabbed content tab components to populate tabbed content pages.',
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_tabbed_content',
    'label' => 'Tabbed Content',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'cabinet' => -1,
        'commission_contact_info' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'fyi' => -1,
        'gol_list_links' => -1,
        'grid_of_places' => -1,
        'grid_of_topics' => -1,
        'group_of_links_grid' => -1,
        'group_of_links_list' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'iframe' => -1,
        'internal_link' => -1,
        'list' => -1,
        'news_announcements' => -1,
        'photo' => -1,
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => -1,
        'tabbed_content_tab' => 'tabbed_content_tab',
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'cabinet' => 3,
        'document' => 4,
        'drawer' => 5,
        'drawers' => 6,
        'external_link' => 7,
        'featured_item' => 8,
        'featured_topics' => 9,
        'fyi' => 10,
        'gol_list_links' => 11,
        'grid_of_places' => 12,
        'grid_of_topics' => 13,
        'group_of_links_grid' => 14,
        'group_of_links_list' => 15,
        'header_text' => 16,
        'hero_image' => 17,
        'iframe' => 18,
        'internal_link' => 19,
        'list' => 20,
        'news_announcements' => 21,
        'photo' => 22,
        'sidebar_item' => 23,
        'sidebar_item_w_icon' => 24,
        'social_media_links' => 25,
        'social_networking' => 26,
        'tabbed_content_tab' => 58,
        'text' => 27,
        'text_one_column' => 28,
        'text_three_column' => 29,
        'text_two_column' => 30,
        'transaction_grid' => 31,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Tab',
      'title_multiple' => 'Tabs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-tabbed_content-field_type_of_content'.
  $field_instances['node-tabbed_content-field_type_of_content'] = array(
    'bundle' => 'tabbed_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select the type of content this piece of content can be filtered by.  NOTE:  This is currently used for the Hub.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_type_of_content',
    'label' => 'Type of Content',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-tabbed_content-field_updated_date'.
  $field_instances['node-tabbed_content-field_updated_date'] = array(
    'bundle' => 'tabbed_content',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'boston_short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_updated_date',
    'label' => 'Updated Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'site-wide',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-tabbed_content_tab-field_component_title'.
  $field_instances['paragraphs_item-tabbed_content_tab-field_component_title'] = array(
    'bundle' => 'tabbed_content_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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

  // Exported field_instance:
  // 'paragraphs_item-tabbed_content_tab-field_components'.
  $field_instances['paragraphs_item-tabbed_content_tab-field_components'] = array(
    'bundle' => 'tabbed_content_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add components to this tab.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_components',
    'label' => 'Components',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => '3_column_w_image',
        'bos311' => 'bos311',
        'bos_signup_emergency_alerts' => 'bos_signup_emergency_alerts',
        'cabinet' => 'cabinet',
        'card' => -1,
        'city_score_dashboard' => -1,
        'commission_contact_info' => -1,
        'commission_summary' => 'commission_summary',
        'commission_members' => 'commission_members',
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'discussion_topic' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => 'drawers',
        'election_results' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => 'featured_topics',
        'feedback' => 'feedback',
        'fyi' => 'fyi',
        'gol_list_links' => -1,
        'grid_of_cards' => 'grid_of_cards',
        'grid_of_people' => 'grid_of_people',
        'grid_of_places' => 'grid_of_places',
        'grid_of_programs_initiatives' => 'grid_of_programs_initiatives',
        'grid_of_quotes' => 'grid_of_quotes',
        'grid_of_topics' => 'grid_of_topics',
        'group_of_links_grid' => 'group_of_links_grid',
        'group_of_links_list' => 'group_of_links_list',
        'group_of_links_mini_grid' => 'group_of_links_mini_grid',
        'header_text' => -1,
        'hero_image' => 'hero_image',
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'iframe' => 'iframe',
        'internal_link' => -1,
        'list' => 'list',
        'map' => 'map',
        'message_for_the_day' => -1,
        'news_announcements' => 'news_announcements',
        'newsletter' => 'newsletter',
        'photo' => 'photo',
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
        'text' => 'text',
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => 'transaction_grid',
        'upcoming_events' => 'upcoming_events',
        'user_action' => -1,
        'video' => 'video',
      ),
      'bundle_weights' => array(
        '3_column_w_image' => -66,
        'bos311' => 3,
        'cabinet' => -65,
        'card' => 5,
        'city_score_dashboard' => 6,
        'custom_hours_text' => 7,
        'daily_hours' => 8,
        'discussion_topic' => 9,
        'document' => -64,
        'drawer' => -63,
        'drawers' => -62,
        'election_results' => 13,
        'external_link' => -61,
        'featured_item' => -60,
        'featured_topics' => -59,
        'feedback' => 17,
        'fyi' => -58,
        'gol_list_links' => -57,
        'grid_of_cards' => 20,
        'grid_of_people' => 21,
        'grid_of_places' => -56,
        'grid_of_programs_initiatives' => 23,
        'grid_of_quotes' => 24,
        'grid_of_topics' => -55,
        'group_of_links_grid' => -54,
        'group_of_links_list' => -53,
        'group_of_links_mini_grid' => -52,
        'header_text' => -51,
        'hero_image' => -50,
        'how_to_contact_step' => 31,
        'how_to_tab' => 32,
        'how_to_text_step' => 33,
        'iframe' => -49,
        'internal_link' => -48,
        'list' => -47,
        'message_for_the_day' => 37,
        'news_announcements' => -46,
        'photo' => -45,
        'quote' => 40,
        'recollect_widget' => 41,
        'script_embed' => 42,
        'seamless_doc' => 43,
        'sidebar_item' => -44,
        'sidebar_item_w_icon' => -43,
        'social_media_links' => -42,
        'social_networking' => -41,
        'status_override' => 48,
        'tabbed_content_tab' => -40,
        'text' => -39,
        'text_one_column' => -38,
        'text_three_column' => -37,
        'text_two_column' => -36,
        'transaction_grid' => -35,
        'upcoming_events' => 55,
        'user_action' => -34,
        'video' => 57,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Component',
      'title_multiple' => 'Components',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add components to this tab.');
  t('Add tabbed content tab components to populate tabbed content pages.');
  t('Components');
  t('Intro Image');
  t('Intro Text');
  t('Please select the type of content this piece of content can be filtered by.  NOTE:  This is currently used for the Hub.');
  t('Published Date');
  t('Tabbed Content');
  t('Title');
  t('Type of Content');
  t('Updated Date');

  return $field_instances;
}
