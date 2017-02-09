<?php
/**
 * @file
 * bos_component_card.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_card_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-card-field_description'.
  $field_instances['paragraphs_item-card-field_description'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
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
    'field_name' => 'field_description',
    'label' => 'Description',
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
        'rows' => 5,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-card-field_image'.
  $field_instances['paragraphs_item-card-field_image'] = array(
    'bundle' => 'card',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_image',
    'label' => 'Column Image',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-card-field_link'.
  $field_instances['paragraphs_item-card-field_link'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_link',
    'label' => 'Call to Action',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'card' => -1,
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
        'grid_of_people' => 20,
        'grid_of_places' => 21,
        'grid_of_programs_initiatives' => 22,
        'grid_of_quotes' => 23,
        'grid_of_topics' => 24,
        'group_of_links_grid' => 25,
        'group_of_links_list' => 26,
        'group_of_links_mini_grid' => 27,
        'header_text' => 28,
        'hero_image' => 29,
        'how_to_contact_step' => 30,
        'how_to_tab' => 31,
        'how_to_text_step' => 32,
        'iframe' => 33,
        'internal_link' => 34,
        'list' => 35,
        'message_for_the_day' => 36,
        'news_announcements' => 37,
        'photo' => 38,
        'quote' => 39,
        'recollect_widget' => 40,
        'script_embed' => 41,
        'seamless_doc' => 42,
        'sidebar_item' => 43,
        'sidebar_item_w_icon' => 44,
        'social_media_links' => 45,
        'social_networking' => 46,
        'status_override' => 47,
        'tabbed_content_tab' => 48,
        'text' => 49,
        'text_one_column' => 50,
        'text_three_column' => 51,
        'text_two_column' => 52,
        'transaction_grid' => 53,
        'upcoming_events' => 54,
        'user_action' => 55,
        'video' => 56,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-card-field_title'.
  $field_instances['paragraphs_item-card-field_title'] = array(
    'bundle' => 'card',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Call to Action');
  t('Column Image');
  t('Description');
  t('Title');

  return $field_instances;
}
