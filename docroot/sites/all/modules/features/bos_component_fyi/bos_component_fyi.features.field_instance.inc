<?php
/**
 * @file
 * bos_component_fyi.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_fyi_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-fyi-field_extra_info'.
  $field_instances['paragraphs_item-fyi-field_extra_info'] = array(
    'bundle' => 'fyi',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '80 character sentence to add to the FYI',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
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
    'field_name' => 'field_extra_info',
    'label' => 'FYI Content',
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
        'size' => 90,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-fyi-field_icon'.
  $field_instances['paragraphs_item-fyi-field_icon'] = array(
    'bundle' => 'fyi',
    'deleted' => 0,
    'description' => 'An SVG icon that is entirely Freedom Trail Red',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_icon',
    'label' => 'Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'fyi-icon-[current-date:file_directory_storage_date]',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-fyi-field_link'.
  $field_instances['paragraphs_item-fyi-field_link'] = array(
    'bundle' => 'fyi',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optional link for users to get more information. Limited to 30 characters.',
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
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'cabinet' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => 'document',
        'external_link' => 'external_link',
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'fyi' => -1,
        'gol_list_links' => -1,
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
        'internal_link' => 'internal_link',
        'list' => -1,
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
        'external_link' => 7,
        'featured_item' => 8,
        'featured_topics' => 9,
        'feedback' => 10,
        'fyi' => 11,
        'gol_list_links' => 12,
        'grid_of_places' => 13,
        'grid_of_programs_initiatives' => 14,
        'grid_of_topics' => 15,
        'group_of_links_grid' => 16,
        'group_of_links_list' => 17,
        'header_text' => 18,
        'hero_image' => 19,
        'how_to_contact_step' => 20,
        'how_to_tab' => 21,
        'how_to_text_step' => 22,
        'internal_link' => 23,
        'list' => 24,
        'news_announcements' => 25,
        'photo' => 26,
        'sidebar_item' => 27,
        'sidebar_item_w_icon' => 28,
        'social_media_links' => 29,
        'social_networking' => 30,
        'text' => 31,
        'text_one_column' => 32,
        'text_three_column' => 33,
        'text_two_column' => 34,
        'transaction_grid' => 35,
      ),
      'default_edit_mode' => 'open',
      'title' => 'link',
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

  // Exported field_instance: 'paragraphs_item-fyi-field_short_title'.
  $field_instances['paragraphs_item-fyi-field_short_title'] = array(
    'bundle' => 'fyi',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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

  // Exported field_instance: 'paragraphs_item-fyi-field_title'.
  $field_instances['paragraphs_item-fyi-field_title'] = array(
    'bundle' => 'fyi',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The title doesn’t have to be the name of a department (“Leaf and Yard Waste Collection”), but it might be (“Public Works”). Limited to 30 characters.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
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
    'field_name' => 'field_title',
    'label' => 'FYI Title',
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
        'size' => 40,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('80 character sentence to add to the FYI');
  t('An SVG icon that is entirely Freedom Trail Red');
  t('Call to Action');
  t('FYI Content');
  t('FYI Title');
  t('Icon');
  t('Optional link for users to get more information. Limited to 30 characters.');
  t('Short Title');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('The title doesn’t have to be the name of a department (“Leaf and Yard Waste Collection”), but it might be (“Public Works”). Limited to 30 characters.');

  return $field_instances;
}
