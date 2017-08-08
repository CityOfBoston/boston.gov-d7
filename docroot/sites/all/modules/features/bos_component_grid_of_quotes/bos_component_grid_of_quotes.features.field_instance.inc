<?php
/**
 * @file
 * bos_component_grid_of_quotes.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_grid_of_quotes_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-grid_of_quotes-field_component_title'.
  $field_instances['paragraphs_item-grid_of_quotes-field_component_title'] = array(
    'bundle' => 'grid_of_quotes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the title of the component. ',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-grid_of_quotes-field_grid_of_quotes'.
  $field_instances['paragraphs_item-grid_of_quotes-field_grid_of_quotes'] = array(
    'bundle' => 'grid_of_quotes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add the quotes that will appear in this grid of quotes component. ',
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
    'field_name' => 'field_grid_of_quotes',
    'label' => 'Grid of Quotes',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => -1,
        'external_link' => -1,
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
        'internal_link' => -1,
        'list' => -1,
        'message_for_the_day' => -1,
        'news_announcements' => -1,
        'photo' => -1,
        'quote' => 'quote',
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => -1,
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
        'grid_of_quotes' => 19,
        'grid_of_topics' => 20,
        'group_of_links_grid' => 21,
        'group_of_links_list' => 22,
        'group_of_links_mini_grid' => 23,
        'header_text' => 24,
        'hero_image' => 25,
        'how_to_contact_step' => 26,
        'how_to_tab' => 27,
        'how_to_text_step' => 28,
        'iframe' => 29,
        'internal_link' => 30,
        'list' => 31,
        'message_for_the_day' => 32,
        'news_announcements' => 33,
        'photo' => 34,
        'quote' => 35,
        'sidebar_item' => 36,
        'sidebar_item_w_icon' => 37,
        'social_media_links' => 38,
        'social_networking' => 39,
        'text' => 40,
        'text_one_column' => 41,
        'text_three_column' => 42,
        'text_two_column' => 43,
        'transaction_grid' => 44,
        'user_action' => 45,
        'video' => 46,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Quote',
      'title_multiple' => 'Quotes',
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

  // Exported field_instance:
  // 'paragraphs_item-grid_of_quotes-field_short_title'.
  $field_instances['paragraphs_item-grid_of_quotes-field_short_title'] = array(
    'bundle' => 'grid_of_quotes',
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add the quotes that will appear in this grid of quotes component. ');
  t('Enter the title of the component. ');
  t('Grid of Quotes');
  t('Short Title');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('Title');

  return $field_instances;
}
