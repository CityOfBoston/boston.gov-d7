<?php
/**
 * @file
 * bos_component_grid_of_cards.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_grid_of_cards_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_children'.
  $field_instances['paragraphs_item-grid_of_cards-field_children'] = array(
    'bundle' => 'grid_of_cards',
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
    'field_name' => 'field_children',
    'label' => 'Cards',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'card' => 'card',
        'city_score_dashboard' => -1,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_contacts'.
  $field_instances['paragraphs_item-grid_of_cards-field_contacts'] = array(
    'bundle' => 'grid_of_cards',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
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
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_contacts',
    'label' => 'All related departments',
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

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_short_title'.
  $field_instances['paragraphs_item-grid_of_cards-field_short_title'] = array(
    'bundle' => 'grid_of_cards',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_short_title',
    'label' => 'Short Title',
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

  // Exported field_instance: 'paragraphs_item-grid_of_cards-field_title'.
  $field_instances['paragraphs_item-grid_of_cards-field_title'] = array(
    'bundle' => 'grid_of_cards',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('All related departments');
  t('Cards');
  t('Short Title');
  t('Title');

  return $field_instances;
}
