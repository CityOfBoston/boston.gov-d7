<?php
/**
 * @file
 * bos_content_type_transaction.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_content_type_transaction_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-transaction-field_description'.
  $field_instances['node-transaction-field_description'] = array(
    'bundle' => 'transaction',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Describe what this transaction is for.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 1,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-transaction-field_link'.
  $field_instances['node-transaction-field_link'] = array(
    'bundle' => 'transaction',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a link to a page/document representing this transaction.',
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
      'listing' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'ribbon_link',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_link',
    'label' => 'Link',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'bos311' => -1,
        'cabinet' => -1,
        'commission_contact_info' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => 'document',
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
        'sidebar_item' => 34,
        'sidebar_item_w_icon' => 35,
        'social_media_links' => 36,
        'social_networking' => 37,
        'text' => 38,
        'text_one_column' => 39,
        'text_three_column' => 40,
        'text_two_column' => 41,
        'transaction_grid' => 42,
        'user_action' => 43,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-transaction-field_sticky'.
  $field_instances['node-transaction-field_sticky'] = array(
    'bundle' => 'transaction',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select whether or not to sticky this item at the top of the Transaction Landing Page.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'listing' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_sticky',
    'label' => 'Sticky',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a link to a page/document representing this transaction.');
  t('Describe what this transaction is for.');
  t('Description');
  t('Link');
  t('Select whether or not to sticky this item at the top of the Transaction Landing Page.');
  t('Sticky');

  return $field_instances;
}
