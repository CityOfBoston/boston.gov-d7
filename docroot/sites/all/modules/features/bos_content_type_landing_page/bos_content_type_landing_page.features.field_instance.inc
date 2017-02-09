<?php
/**
 * @file
 * bos_content_type_landing_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_content_type_landing_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-landing_page-field_components'.
  $field_instances['node-landing_page-field_components'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a list of components that should be displayed on this page. Drag and drop components to adjust the ordering.',
    'display' => array(
      'article' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'calendar_listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'contact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 0,
      ),
      'department_listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_topics' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing_long' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'poll_stub' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'popup_icon' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'published_by' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'topics_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_components',
    'label' => 'Components',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => '3_column_w_image',
        'bos311' => 'bos311',
        'cabinet' => 'cabinet',
        'card' => -1,
        'city_score_dashboard' => -1,
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
        'message_for_the_day' => -1,
        'news_announcements' => 'news_announcements',
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
        '3_column_w_image' => -96,
        'bos311' => -92,
        'cabinet' => -88,
        'card' => 81,
        'city_score_dashboard' => 5,
        'custom_hours_text' => -53,
        'daily_hours' => -52,
        'discussion_topic' => 85,
        'document' => -78,
        'drawer' => -45,
        'drawers' => -68,
        'election_results' => 11,
        'external_link' => -74,
        'featured_item' => -55,
        'featured_topics' => -56,
        'feedback' => -52,
        'fyi' => -48,
        'gol_list_links' => -51,
        'grid_of_cards' => 96,
        'grid_of_people' => -40,
        'grid_of_places' => -36,
        'grid_of_programs_initiatives' => -32,
        'grid_of_quotes' => -22,
        'grid_of_topics' => -28,
        'group_of_links_grid' => -24,
        'group_of_links_list' => -20,
        'group_of_links_mini_grid' => -16,
        'header_text' => -54,
        'hero_image' => -8,
        'how_to_contact_step' => -50,
        'how_to_tab' => -49,
        'how_to_text_step' => -48,
        'iframe' => 8,
        'internal_link' => 16,
        'list' => 20,
        'message_for_the_day' => -44,
        'news_announcements' => 28,
        'photo' => 32,
        'quote' => 37,
        'recollect_widget' => 38,
        'script_embed' => 39,
        'seamless_doc' => 40,
        'sidebar_item' => -47,
        'sidebar_item_w_icon' => -46,
        'social_media_links' => -84,
        'social_networking' => -82,
        'status_override' => 45,
        'tabbed_content_tab' => 125,
        'text' => 52,
        'text_one_column' => 56,
        'text_three_column' => 64,
        'text_two_column' => 60,
        'transaction_grid' => 68,
        'upcoming_events' => 72,
        'user_action' => -43,
        'video' => 76,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_contacts'.
  $field_instances['node-landing_page-field_contacts'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select departments that should be displayed at the bottom of the page.',
    'display' => array(
      'article' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'calendar_listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'contact' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'department_listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'featured_topics' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing_long' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'poll_stub' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'popup_icon' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'published_by' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'topics_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_contacts',
    'label' => 'Contacts',
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
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => 0,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_published_date'.
  $field_instances['node-landing_page-field_published_date'] = array(
    'bundle' => 'landing_page',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
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

  // Exported field_instance: 'node-landing_page-field_type_of_content'.
  $field_instances['node-landing_page-field_type_of_content'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select the type of content this piece of content can be filtered by.  NOTE:  This is currently used for the Hub.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
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

  // Exported field_instance: 'node-landing_page-field_updated_date'.
  $field_instances['node-landing_page-field_updated_date'] = array(
    'bundle' => 'landing_page',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a list of components that should be displayed on this page. Drag and drop components to adjust the ordering.');
  t('Components');
  t('Contacts');
  t('Please select the type of content this piece of content can be filtered by.  NOTE:  This is currently used for the Hub.');
  t('Published Date');
  t('Select departments that should be displayed at the bottom of the page.');
  t('Type of Content');
  t('Updated Date');

  return $field_instances;
}
