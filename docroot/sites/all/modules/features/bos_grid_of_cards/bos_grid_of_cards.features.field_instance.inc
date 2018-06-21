<?php
/**
 * @file
 * bos_grid_of_cards.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_grid_of_cards_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-card-field_link'.
  $field_instances['paragraphs_item-card-field_link'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is where the card links to. Only the URL is used, <strong>the title is not displayed</strong> on the card.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
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
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_link',
    'label' => 'Call to Action',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bid' => -1,
        'bos311' => -1,
        'bos_signup_emergency_alerts' => -1,
        'cabinet' => -1,
        'card' => -1,
        'city_score_dashboard' => -1,
        'commission_contact_info' => -1,
        'commission_summary' => -1,
        'commission_members' => -1,
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
        'grid_of_cards' => -1,
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
        'lightbox_link' => 'lightbox_link',
        'list' => -1,
        'map' => -1,
        'map_coordinates' => -1,
        'map_esri_feed' => -1,
        'map_pin' => -1,
        'message_for_the_day' => -1,
        'news_announcements' => -1,
        'newsletter' => -1,
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
        'bid' => 60,
        'bos311' => 3,
        'bos_signup_emergency_alerts' => 62,
        'cabinet' => 4,
        'card' => 5,
        'city_score_dashboard' => 6,
        'commission_contact_info' => 66,
        'commission_members' => 67,
        'commission_summary' => 68,
        'custom_hours_text' => 7,
        'daily_hours' => 8,
        'discussion_topic' => 9,
        'document' => 10,
        'drawer' => 11,
        'drawers' => 12,
        'election_results' => 13,
        'external_link' => 14,
        'featured_item' => 15,
        'featured_topics' => 16,
        'feedback' => 17,
        'fyi' => 18,
        'gol_list_links' => 19,
        'grid_of_cards' => 20,
        'grid_of_people' => 21,
        'grid_of_places' => 22,
        'grid_of_programs_initiatives' => 23,
        'grid_of_quotes' => 24,
        'grid_of_topics' => 25,
        'group_of_links_grid' => 26,
        'group_of_links_list' => 27,
        'group_of_links_mini_grid' => 28,
        'header_text' => 29,
        'hero_image' => 30,
        'how_to_contact_step' => 31,
        'how_to_tab' => 32,
        'how_to_text_step' => 33,
        'iframe' => 34,
        'internal_link' => 35,
        'lightbox_link' => 97,
        'list' => 36,
        'map' => 99,
        'map_coordinates' => 100,
        'map_esri_feed' => 101,
        'map_pin' => 102,
        'message_for_the_day' => 37,
        'news_announcements' => 38,
        'newsletter' => 104,
        'photo' => 39,
        'quote' => 40,
        'recollect_widget' => 41,
        'script_embed' => 42,
        'seamless_doc' => 43,
        'sidebar_item' => 44,
        'sidebar_item_w_icon' => 45,
        'social_media_links' => 46,
        'social_networking' => 47,
        'status_override' => 48,
        'tabbed_content_tab' => 49,
        'text' => 50,
        'text_one_column' => 51,
        'text_three_column' => 52,
        'text_two_column' => 53,
        'transaction_grid' => 54,
        'upcoming_events' => 55,
        'user_action' => 56,
        'video' => 57,
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

  // Exported field_instance: 'paragraphs_item-card-field_short_description'.
  $field_instances['paragraphs_item-card-field_short_description'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A brief description of the card. <strong>Display is limited to 140 characters.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 140,
        ),
        'type' => 'text_trimmed',
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
    'field_name' => 'field_short_description',
    'label' => 'Short Description',
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
        'size' => 80,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-card-field_subheader'.
  $field_instances['paragraphs_item-card-field_subheader'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Leave blank if no sub-title. Will display in all-caps Montserrat below title. <strong>Display is limited to 70 characters.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 70,
        ),
        'type' => 'text_trimmed',
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
    'field_name' => 'field_subheader',
    'label' => 'Sub-Title',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-card-field_thumbnail'.
  $field_instances['paragraphs_item-card-field_thumbnail'] = array(
    'bundle' => 'card',
    'deleted' => 0,
    'description' => 'This image will appear as a banner on the card.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_url_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'featured_item_thumbnail',
          'url_type' => 0,
        ),
        'type' => 'image_url',
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
    'field_name' => 'field_thumbnail',
    'label' => 'Card Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
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
          'boston_media_browser_tabs--boston_media' => 0,
          'boston_media_browser_tabs--icons' => 0,
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-card-field_title'.
  $field_instances['paragraphs_item-card-field_title'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The title for the card. <strong>Display is limited to 70 characters.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 70,
        ),
        'type' => 'text_trimmed',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-grid_of_cards-field_component_theme'.
  $field_instances['paragraphs_item-grid_of_cards-field_component_theme'] = array(
    'bundle' => 'grid_of_cards',
    'default_value' => array(
      0 => array(
        'value' => 'g',
      ),
    ),
    'deleted' => 0,
    'description' => 'This will change the colors output for the component. This component defaults to the grey theme, but supports white, or blue.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
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
    'fences_wrapper' => 'no_wrapper',
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
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-grid_of_cards-field_component_title'.
  $field_instances['paragraphs_item-grid_of_cards-field_component_title'] = array(
    'bundle' => 'grid_of_cards',
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
    'fences_wrapper' => 'div_div_div',
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

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_contact'.
  $field_instances['paragraphs_item-grid_of_cards-field_contact'] = array(
    'bundle' => 'grid_of_cards',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Which department is the best point of contact for this component.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'use_content_language' => TRUE,
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
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_drawer'.
  $field_instances['paragraphs_item-grid_of_cards-field_drawer'] = array(
    'bundle' => 'grid_of_cards',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add cards to this grid of cards component. Ideally, there should be in multiples of 4 with up to 12 cards max.',
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
    'field_name' => 'field_drawer',
    'label' => 'Cards',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'card' => 'card',
        'city_score_dashboard' => -1,
        'commission_contact_info' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'discussion_topic' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => -1,
        'election_results' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'fyi' => -1,
        'gol_list_links' => -1,
        'grid_of_cards' => -1,
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
        'internal_link' => -1,
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
        'card' => 5,
        'city_score_dashboard' => 6,
        'custom_hours_text' => 7,
        'daily_hours' => 8,
        'discussion_topic' => 9,
        'document' => 10,
        'drawer' => 11,
        'drawers' => 12,
        'election_results' => 13,
        'external_link' => 14,
        'featured_item' => 15,
        'featured_topics' => 16,
        'feedback' => 17,
        'fyi' => 18,
        'gol_list_links' => 19,
        'grid_of_cards' => 20,
        'grid_of_people' => 21,
        'grid_of_places' => 22,
        'grid_of_programs_initiatives' => 23,
        'grid_of_quotes' => 24,
        'grid_of_topics' => 25,
        'group_of_links_grid' => 26,
        'group_of_links_list' => 27,
        'group_of_links_mini_grid' => 28,
        'header_text' => 29,
        'hero_image' => 30,
        'how_to_contact_step' => 31,
        'how_to_tab' => 32,
        'how_to_text_step' => 33,
        'iframe' => 34,
        'internal_link' => 35,
        'list' => 36,
        'message_for_the_day' => 37,
        'news_announcements' => 38,
        'photo' => 39,
        'quote' => 40,
        'recollect_widget' => 41,
        'script_embed' => 42,
        'seamless_doc' => 43,
        'sidebar_item' => 44,
        'sidebar_item_w_icon' => 45,
        'social_media_links' => 46,
        'social_networking' => 47,
        'status_override' => 48,
        'tabbed_content_tab' => 49,
        'text' => 50,
        'text_one_column' => 51,
        'text_three_column' => 52,
        'text_two_column' => 53,
        'transaction_grid' => 54,
        'upcoming_events' => 55,
        'user_action' => 56,
        'video' => 57,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
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

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_short_title'.
  $field_instances['paragraphs_item-grid_of_cards-field_short_title'] = array(
    'bundle' => 'grid_of_cards',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.',
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
  t('A brief description of the card. <strong>Display is limited to 140 characters.</strong>');
  t('Add cards to this grid of cards component. Ideally, there should be in multiples of 4 with up to 12 cards max.');
  t('Call to Action');
  t('Card Image');
  t('Cards');
  t('Component Theme');
  t('Contact');
  t('Leave blank if no sub-title. Will display in all-caps Montserrat below title. <strong>Display is limited to 70 characters.</strong>');
  t('Short Description');
  t('Short Title');
  t('Sub-Title');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('The title for the card. <strong>Display is limited to 70 characters.</strong>');
  t('This image will appear as a banner on the card.');
  t('This is where the card links to. Only the URL is used, <strong>the title is not displayed</strong> on the card.');
  t('This will change the colors output for the component. This component defaults to the grey theme, but supports white, or blue.');
  t('Title');
  t('Which department is the best point of contact for this component.');

  return $field_instances;
}
