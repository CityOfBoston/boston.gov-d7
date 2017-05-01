<?php
/**
 * @file
 * bos_component_gol_grid.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_gol_grid_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_grid_links-field_extra_info'
  $field_instances['field_collection_item-field_grid_links-field_extra_info'] = array(
    'bundle' => 'field_grid_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Place a phone number or email that can display on a resource.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'group_of_links' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_extra_info',
    'label' => 'Extra Info',
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

  // Exported field_instance: 'field_collection_item-field_grid_links-field_grid_link'
  $field_instances['field_collection_item-field_grid_links-field_grid_link'] = array(
    'bundle' => 'field_grid_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the type of link you would like to insert.',
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
      'group_of_links' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'separated_title',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_grid_link',
    'label' => 'Grid Link',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'document' => 'document',
        'external_link' => 'external_link',
        'group_of_links_grid' => -1,
        'internal_link' => 'internal_link',
      ),
      'bundle_weights' => array(
        'document' => 2,
        'external_link' => 3,
        'group_of_links_grid' => 4,
        'internal_link' => 5,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_grid_links-field_short_description'
  $field_instances['field_collection_item-field_grid_links-field_short_description'] = array(
    'bundle' => 'field_grid_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'group_of_links' => array(
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
          'trim_length' => 75,
          'use_summary' => 0,
          'word_boundary' => 1,
        ),
        'type' => 'advanced_text',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_short_description',
    'label' => 'Short Description',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_component_title'
  $field_instances['paragraphs_item-group_of_links_grid-field_component_title'] = array(
    'bundle' => 'group_of_links_grid',
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
        'label' => 'hidden',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_contact'
  $field_instances['paragraphs_item-group_of_links_grid-field_contact'] = array(
    'bundle' => 'group_of_links_grid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'contact',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_description'
  $field_instances['paragraphs_item-group_of_links_grid-field_description'] = array(
    'bundle' => 'group_of_links_grid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Additional text to provide the user with more information about this group of links.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_grid_links'
  $field_instances['paragraphs_item-group_of_links_grid-field_grid_links'] = array(
    'bundle' => 'group_of_links_grid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'group_of_links',
        ),
        'type' => 'field_collection_fields',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
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
    'field_name' => 'field_grid_links',
    'label' => 'Grid Links',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_link'
  $field_instances['paragraphs_item-group_of_links_grid-field_link'] = array(
    'bundle' => 'group_of_links_grid',
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
        'bos311' => -1,
        'cabinet' => -1,
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
        'video' => 44,
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_short_title'
  $field_instances['paragraphs_item-group_of_links_grid-field_short_title'] = array(
    'bundle' => 'group_of_links_grid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => '',
          'title_style' => '',
        ),
        'type' => 'title_linked',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-group_of_links_grid-field_subheader'
  $field_instances['paragraphs_item-group_of_links_grid-field_subheader'] = array(
    'bundle' => 'group_of_links_grid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional text to provide the user with more information about this group of links.');
  t('Call to Action');
  t('Contact');
  t('Description');
  t('Extra Info');
  t('Grid Link');
  t('Grid Links');
  t('Place a phone number or email that can display on a resource.');
  t('Select the type of link you would like to insert.');
  t('Short Description');
  t('Short Title');
  t('Subheader');
  t('The short title is used to populate the in-page navigation. Please keep it short: one to three words is ideal. Example can be found on boston.gov/winter/.');
  t('The title of the component that is displayed on the top of this component.');
  t('Title');

  return $field_instances;
}
