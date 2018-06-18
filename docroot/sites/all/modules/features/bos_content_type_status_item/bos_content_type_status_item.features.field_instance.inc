<?php
/**
 * @file
 * bos_content_type_status_item.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_content_type_status_item_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-status_item-field_icon'.
  $field_instances['node-status_item-field_icon'] = array(
    'bundle' => 'status_item',
    'deleted' => 0,
    'description' => 'Set the icon representing this status. The dimensions for this icon should be 50x50.',
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
        'weight' => 2,
      ),
      'listing' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_icon',
    'label' => 'Status Icon',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'status-item-icon-[current-date:file_directory_storage_date]',
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
          'boston_media_browser_tabs--boston_media' => 0,
          'boston_media_browser_tabs--icons' => 'boston_media_browser_tabs--icons',
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-status_item-field_messages'.
  $field_instances['node-status_item-field_messages'] = array(
    'bundle' => 'status_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add messages to be displayed with this status item.',
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
      'teaser' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_messages',
    'label' => 'Messages',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'cabinet' => -1,
        'commission_contact_info' => -1,
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
        'grid_of_topics' => -1,
        'group_of_links_grid' => -1,
        'group_of_links_list' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'iframe' => -1,
        'internal_link' => -1,
        'list' => -1,
        'message_for_the_day' => 'message_for_the_day',
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
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'cabinet' => 3,
        'custom_hours_text' => 4,
        'daily_hours' => 5,
        'document' => 6,
        'drawer' => 7,
        'drawers' => 8,
        'external_link' => 9,
        'featured_item' => 10,
        'featured_topics' => 11,
        'feedback' => 12,
        'fyi' => 13,
        'gol_list_links' => 14,
        'grid_of_people' => 15,
        'grid_of_places' => 16,
        'grid_of_programs_initiatives' => 17,
        'grid_of_topics' => 18,
        'group_of_links_grid' => 19,
        'group_of_links_list' => 20,
        'header_text' => 21,
        'hero_image' => 22,
        'how_to_contact_step' => 23,
        'how_to_tab' => 24,
        'how_to_text_step' => 25,
        'iframe' => 26,
        'internal_link' => 27,
        'list' => 28,
        'message_for_the_day' => 29,
        'news_announcements' => 30,
        'photo' => 31,
        'sidebar_item' => 32,
        'sidebar_item_w_icon' => 33,
        'social_media_links' => 34,
        'social_networking' => 35,
        'text' => 36,
        'text_one_column' => 37,
        'text_three_column' => 38,
        'text_two_column' => 39,
        'transaction_grid' => 40,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Message',
      'title_multiple' => 'Messages',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-status_item-field_title'.
  $field_instances['node-status_item-field_title'] = array(
    'bundle' => 'status_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Set the display title for this item.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'listing' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_title',
    'label' => 'Display Title',
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

  // Exported field_instance: 'paragraphs_item-message_for_the_day-field_date'.
  $field_instances['paragraphs_item-message_for_the_day-field_date'] = array(
    'bundle' => 'message_for_the_day',
    'deleted' => 0,
    'description' => 'The date associated with particular message text.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_date',
    'label' => 'Date',
    'required' => 0,
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
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 1,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-message_for_the_day-field_link'.
  $field_instances['paragraphs_item-message_for_the_day-field_link'] = array(
    'bundle' => 'message_for_the_day',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally include a link to a resource which provides additional details.',
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_link',
    'label' => 'Details',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
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
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'cabinet' => 3,
        'custom_hours_text' => 4,
        'daily_hours' => 5,
        'document' => 6,
        'drawer' => 7,
        'drawers' => 8,
        'external_link' => 9,
        'featured_item' => 10,
        'featured_topics' => 11,
        'feedback' => 12,
        'fyi' => 13,
        'gol_list_links' => 14,
        'grid_of_people' => 15,
        'grid_of_places' => 16,
        'grid_of_programs_initiatives' => 17,
        'grid_of_topics' => 18,
        'group_of_links_grid' => 19,
        'group_of_links_list' => 20,
        'header_text' => 21,
        'hero_image' => 22,
        'how_to_contact_step' => 23,
        'how_to_tab' => 24,
        'how_to_text_step' => 25,
        'iframe' => 26,
        'internal_link' => 27,
        'list' => 28,
        'message_for_the_day' => 29,
        'news_announcements' => 30,
        'photo' => 31,
        'sidebar_item' => 32,
        'sidebar_item_w_icon' => 33,
        'social_media_links' => 34,
        'social_networking' => 35,
        'text' => 36,
        'text_one_column' => 37,
        'text_three_column' => 38,
        'text_two_column' => 39,
        'transaction_grid' => 40,
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

  // Exported field_instance:
  // 'paragraphs_item-message_for_the_day-field_message'.
  $field_instances['paragraphs_item-message_for_the_day-field_message'] = array(
    'bundle' => 'message_for_the_day',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Set the message text relative to the date configuration.',
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
    'field_name' => 'field_message',
    'label' => 'Message',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-message_for_the_day-field_use_alert'.
  $field_instances['paragraphs_item-message_for_the_day-field_use_alert'] = array(
    'bundle' => 'message_for_the_day',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check to use the alert icon specified in the status item.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_use_alert',
    'label' => 'Use alert',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add messages to be displayed with this status item.');
  t('Check to use the alert icon specified in the status item.');
  t('Date');
  t('Details');
  t('Display Title');
  t('Message');
  t('Messages');
  t('Optionally include a link to a resource which provides additional details.');
  t('Set the display title for this item.');
  t('Set the icon representing this status. The dimensions for this icon should be 50x50.');
  t('Set the message text relative to the date configuration.');
  t('Status Icon');
  t('The date associated with particular message text.');
  t('Use alert');

  return $field_instances;
}
