<?php
/**
 * @file
 * bos_content_type_how_to.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_content_type_how_to_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-how_to-body'.
  $field_instances['node-how_to-body'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'listing' => array(
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
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'body',
    'label' => 'Intro Text',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
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
        'rows' => 20,
        'show_token_tree' => 0,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-how_to-field_contact'.
  $field_instances['node-how_to-field_contact'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add contact information for this how-to.',
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
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'view_mode' => 'article',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 4,
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
      'listing' => array(
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_contact',
    'label' => 'Contact',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-how_to-field_how_to_tabs'.
  $field_instances['node-how_to-field_how_to_tabs'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add how-to tabs through this field.',
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
        'weight' => 2,
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
      'listing' => array(
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_how_to_tabs',
    'label' => 'How-To Tabs',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'commission_contact_info' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'group_of_links_grid' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => 'how_to_tab',
        'how_to_text_step' => -1,
        'internal_link' => -1,
        'list' => -1,
        'photo' => -1,
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'custom_hours_text' => 22,
        'daily_hours' => 23,
        'document' => 3,
        'external_link' => 4,
        'featured_item' => 5,
        'featured_topics' => 6,
        'feedback' => 7,
        'group_of_links_grid' => 8,
        'header_text' => 9,
        'hero_image' => 10,
        'how_to_contact_step' => 32,
        'how_to_tab' => 33,
        'how_to_text_step' => 34,
        'internal_link' => 11,
        'list' => 12,
        'photo' => 14,
        'text' => 15,
        'text_one_column' => 16,
        'text_three_column' => 17,
        'text_two_column' => 18,
        'transaction_grid' => 19,
      ),
      'default_edit_mode' => 'open',
      'title' => 'How-To Tab',
      'title_multiple' => 'How-To Tabs',
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

  // Exported field_instance: 'node-how_to-field_intro_image'.
  $field_instances['node-how_to-field_intro_image'] = array(
    'bundle' => 'how_to',
    'deleted' => 0,
    'description' => 'Add an intro-image to the how-to page. This will appear at the very top of the page in a hero image pattern.',
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
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
      'listing' => array(
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_intro_image',
    'label' => 'Intro Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'how-to-intro-image-[current-date:file_directory_storage_date]',
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
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-how_to-field_links'.
  $field_instances['node-how_to-field_links'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
        'weight' => 5,
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
      'listing' => array(
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_links',
    'label' => 'Downloads',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'commission_contact_info' => -1,
        'document' => 'document',
        'external_link' => 'external_link',
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'group_of_links_grid' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'internal_link' => 'internal_link',
        'list' => -1,
        'photo' => -1,
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'document' => 3,
        'external_link' => 4,
        'featured_item' => 5,
        'featured_topics' => 6,
        'feedback' => 7,
        'group_of_links_grid' => 8,
        'header_text' => 9,
        'hero_image' => 10,
        'internal_link' => 11,
        'list' => 12,
        'photo' => 14,
        'text' => 15,
        'text_one_column' => 16,
        'text_three_column' => 17,
        'text_two_column' => 18,
        'transaction_grid' => 19,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Download',
      'title_multiple' => 'Downloads',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-how_to-field_need_to_know'.
  $field_instances['node-how_to-field_need_to_know'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add need-to-know information for this how-to here.',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
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
      'listing' => array(
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_need_to_know',
    'label' => 'Need to Know',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => FALSE,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-how_to-field_payment_info'.
  $field_instances['node-how_to-field_payment_info'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter payment info associated with this how-to here.',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
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
      'listing' => array(
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
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_payment_info',
    'label' => 'Payment Info',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => FALSE,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-how_to-field_published_date'.
  $field_instances['node-how_to-field_published_date'] = array(
    'bundle' => 'how_to',
    'deleted' => 0,
    'description' => 'Add the date this content is effectively published.',
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
        'module' => 'date',
        'settings' => array(
          'format_type' => 'normal_date',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 8,
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
      'listing' => array(
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
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-how_to-field_type_of_content'.
  $field_instances['node-how_to-field_type_of_content'] = array(
    'bundle' => 'how_to',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select the type of content this piece of content can be filtered by.  NOTE:  This is currently used for the Hub.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
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
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-how_to-field_updated_date'.
  $field_instances['node-how_to-field_updated_date'] = array(
    'bundle' => 'how_to',
    'deleted' => 0,
    'description' => 'Enter the last time this content was effectively updated at.',
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
        'weight' => 9,
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
      'listing' => array(
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
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-how_to_contact_step-field_address'.
  $field_instances['paragraphs_item-how_to_contact_step-field_address'] = array(
    'bundle' => 'how_to_contact_step',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A step providing contact information for a How-To Tab.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
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
    'field_name' => 'field_address',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'US' => 'US',
        ),
        'default_country' => 'US',
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-how_to_contact_step-field_operation_hours'.
  $field_instances['paragraphs_item-how_to_contact_step-field_operation_hours'] = array(
    'bundle' => 'how_to_contact_step',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_operation_hours',
    'label' => 'Operation Hours',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'commission_contact_info' => -1,
        'custom_hours_text' => 'custom_hours_text',
        'daily_hours' => 'daily_hours',
        'document' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'group_of_links_grid' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'internal_link' => -1,
        'list' => -1,
        'photo' => -1,
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'custom_hours_text' => 3,
        'daily_hours' => 4,
        'document' => 5,
        'external_link' => 6,
        'featured_item' => 7,
        'featured_topics' => 8,
        'feedback' => 9,
        'group_of_links_grid' => 10,
        'header_text' => 11,
        'hero_image' => 12,
        'how_to_contact_step' => 13,
        'how_to_tab' => 14,
        'how_to_text_step' => 15,
        'internal_link' => 16,
        'list' => 17,
        'photo' => 19,
        'text' => 20,
        'text_one_column' => 21,
        'text_three_column' => 22,
        'text_two_column' => 23,
        'transaction_grid' => 24,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Operation Hours',
      'title_multiple' => 'Operation Hours',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-how_to_contact_step-field_step_details'.
  $field_instances['paragraphs_item-how_to_contact_step-field_step_details'] = array(
    'bundle' => 'how_to_contact_step',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_step_details',
    'label' => 'Contact Step Details',
    'required' => 0,
    'settings' => array(
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-how_to_contact_step-field_title'.
  $field_instances['paragraphs_item-how_to_contact_step-field_title'] = array(
    'bundle' => 'how_to_contact_step',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the step label.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_title',
    'label' => 'Step Label',
    'required' => 1,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-how_to_tab-field_how_to_steps'.
  $field_instances['paragraphs_item-how_to_tab-field_how_to_steps'] = array(
    'bundle' => 'how_to_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add how-to steps to display to the user here.',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_how_to_steps',
    'label' => 'How-To Steps',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'commission_contact_info' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'group_of_links_grid' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => 'how_to_contact_step',
        'how_to_tab' => -1,
        'how_to_text_step' => 'how_to_text_step',
        'internal_link' => -1,
        'list' => -1,
        'photo' => -1,
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => 2,
        'custom_hours_text' => 23,
        'daily_hours' => 24,
        'document' => 3,
        'external_link' => 4,
        'featured_item' => 5,
        'featured_topics' => 6,
        'feedback' => 7,
        'group_of_links_grid' => 8,
        'header_text' => 9,
        'hero_image' => 10,
        'how_to_contact_step' => 33,
        'how_to_tab' => 11,
        'how_to_text_step' => 35,
        'internal_link' => 12,
        'list' => 13,
        'photo' => 15,
        'text' => 16,
        'text_one_column' => 17,
        'text_three_column' => 18,
        'text_two_column' => 19,
        'transaction_grid' => 20,
      ),
      'default_edit_mode' => 'open',
      'title' => 'How-To Step',
      'title_multiple' => 'How-To Steps',
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

  // Exported field_instance: 'paragraphs_item-how_to_tab-field_how_to_title'.
  $field_instances['paragraphs_item-how_to_tab-field_how_to_title'] = array(
    'bundle' => 'how_to_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Set the title of the tab.',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_how_to_title',
    'label' => 'Tab Title',
    'required' => 1,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-how_to_tab-field_keep_in_mind'.
  $field_instances['paragraphs_item-how_to_tab-field_keep_in_mind'] = array(
    'bundle' => 'how_to_tab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add additional notes to keep in mind when considering the subject presented by this tab.',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_keep_in_mind',
    'label' => 'Keep in Mind',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => FALSE,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-how_to_text_step-field_step_details'.
  $field_instances['paragraphs_item-how_to_text_step-field_step_details'] = array(
    'bundle' => 'how_to_text_step',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Fill in step details.',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_step_details',
    'label' => 'Step Details',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => FALSE,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-how_to_text_step-field_title'.
  $field_instances['paragraphs_item-how_to_text_step-field_title'] = array(
    'bundle' => 'how_to_text_step',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the step label.',
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
    'field_name' => 'field_title',
    'label' => 'Step Label',
    'required' => 1,
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A step providing contact information for a How-To Tab.');
  t('Add additional notes to keep in mind when considering the subject presented by this tab.');
  t('Add an intro-image to the how-to page. This will appear at the very top of the page in a hero image pattern.');
  t('Add contact information for this how-to.');
  t('Add how-to steps to display to the user here.');
  t('Add how-to tabs through this field.');
  t('Add need-to-know information for this how-to here.');
  t('Add the date this content is effectively published.');
  t('Contact');
  t('Contact Step Details');
  t('Downloads');
  t('Enter payment info associated with this how-to here.');
  t('Enter the last time this content was effectively updated at.');
  t('Enter the step label.');
  t('Fill in step details.');
  t('How-To Steps');
  t('How-To Tabs');
  t('Intro Image');
  t('Intro Text');
  t('Keep in Mind');
  t('Location');
  t('Need to Know');
  t('Operation Hours');
  t('Payment Info');
  t('Please select the type of content this piece of content can be filtered by.  NOTE:  This is currently used for the Hub.');
  t('Published Date');
  t('Set the title of the tab.');
  t('Step Details');
  t('Step Label');
  t('Tab Title');
  t('Type of Content');
  t('Updated Date');

  return $field_instances;
}
