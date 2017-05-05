<?php
/**
 * @file
 * bos_component_user_action.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_user_action_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-user_action-field_image'
  $field_instances['paragraphs_item-user_action-field_image'] = array(
    'bundle' => 'user_action',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'background_image_formatter',
        'settings' => array(
          'background_image_output_type' => 'css',
          'background_image_selector' => '.user-action-background',
          'image_style' => '',
        ),
        'type' => 'background_image_formatter',
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
    'field_name' => 'field_image',
    'label' => 'Background Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'user-action-image-[current-date:file_directory_storage_date]',
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
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-user_action-field_intro_text'
  $field_instances['paragraphs_item-user_action-field_intro_text'] = array(
    'bundle' => 'user_action',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'field_name' => 'field_intro_text',
    'label' => 'Intro Text',
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
        'rows' => 5,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-user_action-field_links'
  $field_instances['paragraphs_item-user_action-field_links'] = array(
    'bundle' => 'user_action',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'select_list',
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
    'field_name' => 'field_links',
    'label' => 'List of Links',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'cabinet' => -1,
        'document' => 'document',
        'drawer' => -1,
        'drawers' => -1,
        'external_link' => 'external_link',
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
        'internal_link' => 'internal_link',
        'list' => -1,
        'news_announcements' => -1,
        'photo' => -1,
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => -1,
        'tabbed_content_tab' => -1,
        'text' => -1,
        'text_one_column' => -1,
        'text_three_column' => -1,
        'text_two_column' => -1,
        'transaction_grid' => -1,
        'user_action' => -1,
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
        'tabbed_content_tab' => 27,
        'text' => 28,
        'text_one_column' => 29,
        'text_three_column' => 30,
        'text_two_column' => 31,
        'transaction_grid' => 32,
        'user_action' => 33,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-user_action-field_short_title'
  $field_instances['paragraphs_item-user_action-field_short_title'] = array(
    'bundle' => 'user_action',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Image');
  t('Intro Text');
  t('List of Links');
  t('Short Title');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');

  return $field_instances;
}
