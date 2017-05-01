<?php
/**
 * @file
 * bos_component_gol_list.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_gol_list_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-gol_list_links-field_description'
  $field_instances['paragraphs_item-gol_list_links-field_description'] = array(
    'bundle' => 'gol_list_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'advanced_text_formatter',
        'settings' => array(
          'allowed_html' => array(
            0 => 'b',
            1 => 'em',
            2 => 'i',
            3 => 'strong',
          ),
          'autop' => 0,
          'ellipsis' => 1,
          'filter' => 'php',
          'format' => 'plain_text',
          'token_replace' => 0,
          'trim_length' => 125,
          'use_summary' => 0,
          'word_boundary' => 1,
        ),
        'type' => 'advanced_text',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
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
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-gol_list_links-field_link'
  $field_instances['paragraphs_item-gol_list_links-field_link'] = array(
    'bundle' => 'gol_list_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the type of link you would like to insert, and then enter the title and destination. The title should be no longer than 30 characters.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'ribbon_link',
        ),
        'type' => 'paragraphs_view',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
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
    'field_name' => 'field_link',
    'label' => 'List Link',
    'required' => 1,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => 'document',
        'external_link' => 'external_link',
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'gol_list_links' => -1,
        'group_of_links_grid' => -1,
        'group_of_links_list' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'internal_link' => 'internal_link',
        'list' => -1,
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
        'custom_hours_text' => 3,
        'daily_hours' => 4,
        'document' => 5,
        'external_link' => 6,
        'featured_item' => 7,
        'featured_topics' => 8,
        'feedback' => 9,
        'gol_list_links' => 10,
        'group_of_links_grid' => 11,
        'group_of_links_list' => 12,
        'header_text' => 13,
        'hero_image' => 14,
        'how_to_contact_step' => 15,
        'how_to_tab' => 16,
        'how_to_text_step' => 17,
        'internal_link' => 18,
        'list' => 19,
        'photo' => 20,
        'sidebar_item' => 21,
        'sidebar_item_w_icon' => 22,
        'social_media_links' => 23,
        'social_networking' => 24,
        'text' => 25,
        'text_one_column' => 26,
        'text_three_column' => 27,
        'text_two_column' => 28,
        'transaction_grid' => 29,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_component_title'
  $field_instances['paragraphs_item-group_of_links_list-field_component_title'] = array(
    'bundle' => 'group_of_links_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The title of the component that is displayed on the top of this component.',
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
      'ribbon_link' => array(
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
    'fences_wrapper' => 'h2',
    'field_name' => 'field_component_title',
    'label' => 'Title',
    'required' => 0,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_contact'
  $field_instances['paragraphs_item-group_of_links_list-field_contact'] = array(
    'bundle' => 'group_of_links_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select a Contact who owns this content. The contact will be displayed on the component to give users a way to get in contact with the owner.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
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
      'ribbon_link' => array(
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
    'field_name' => 'field_contact',
    'label' => 'Contact',
    'required' => 0,
    'settings' => array(
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_description'
  $field_instances['paragraphs_item-group_of_links_list-field_description'] = array(
    'bundle' => 'group_of_links_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Additional text to provide the user with more information about this group of links.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
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
    'field_name' => 'field_description',
    'label' => 'Description',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_link'
  $field_instances['paragraphs_item-group_of_links_list-field_link'] = array(
    'bundle' => 'group_of_links_list',
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
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
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
    'field_name' => 'field_link',
    'label' => 'Call to Action',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => 'document',
        'external_link' => 'external_link',
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'gol_list_links' => -1,
        'group_of_links_grid' => -1,
        'group_of_links_list' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'internal_link' => 'internal_link',
        'list' => -1,
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
        'custom_hours_text' => 3,
        'daily_hours' => 4,
        'document' => 5,
        'external_link' => 6,
        'featured_item' => 7,
        'featured_topics' => 8,
        'feedback' => 9,
        'gol_list_links' => 10,
        'group_of_links_grid' => 11,
        'group_of_links_list' => 12,
        'header_text' => 13,
        'hero_image' => 14,
        'how_to_contact_step' => 15,
        'how_to_tab' => 16,
        'how_to_text_step' => 17,
        'internal_link' => 18,
        'list' => 19,
        'photo' => 20,
        'sidebar_item' => 21,
        'sidebar_item_w_icon' => 22,
        'social_media_links' => 23,
        'social_networking' => 24,
        'text' => 25,
        'text_one_column' => 26,
        'text_three_column' => 27,
        'text_two_column' => 28,
        'transaction_grid' => 29,
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_list_links'
  $field_instances['paragraphs_item-group_of_links_list-field_list_links'] = array(
    'bundle' => 'group_of_links_list',
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
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
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
    'field_name' => 'field_list_links',
    'label' => 'List Links',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'custom_hours_text' => -1,
        'daily_hours' => -1,
        'document' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'gol_list_links' => 'gol_list_links',
        'group_of_links_grid' => -1,
        'group_of_links_list' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'how_to_contact_step' => -1,
        'how_to_tab' => -1,
        'how_to_text_step' => -1,
        'internal_link' => -1,
        'list' => -1,
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
        'custom_hours_text' => 3,
        'daily_hours' => 4,
        'document' => 5,
        'external_link' => 6,
        'featured_item' => 7,
        'featured_topics' => 8,
        'feedback' => 9,
        'gol_list_links' => 10,
        'group_of_links_grid' => 11,
        'group_of_links_list' => 12,
        'header_text' => 13,
        'hero_image' => 14,
        'how_to_contact_step' => 15,
        'how_to_tab' => 16,
        'how_to_text_step' => 17,
        'internal_link' => 18,
        'list' => 19,
        'photo' => 20,
        'sidebar_item' => 21,
        'sidebar_item_w_icon' => 22,
        'social_media_links' => 23,
        'social_networking' => 24,
        'text' => 25,
        'text_one_column' => 26,
        'text_three_column' => 27,
        'text_two_column' => 28,
        'transaction_grid' => 29,
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_short_title'
  $field_instances['paragraphs_item-group_of_links_list-field_short_title'] = array(
    'bundle' => 'group_of_links_list',
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
      'ribbon_link' => array(
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

  // Exported field_instance: 'paragraphs_item-group_of_links_list-field_subheader'
  $field_instances['paragraphs_item-group_of_links_list-field_subheader'] = array(
    'bundle' => 'group_of_links_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
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
      'ribbon_link' => array(
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
    'field_name' => 'field_subheader',
    'label' => 'Subheader',
    'required' => 0,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional text to provide the user with more information about this group of links.');
  t('Call to Action');
  t('Contact');
  t('Description');
  t('List Link');
  t('List Links');
  t('Please select a Contact who owns this content. The contact will be displayed on the component to give users a way to get in contact with the owner.');
  t('Select the type of link you would like to insert, and then enter the title and destination. The title should be no longer than 30 characters.');
  t('Short Title');
  t('Subheader');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('The title of the component that is displayed on the top of this component.');
  t('Title');

  return $field_instances;
}
