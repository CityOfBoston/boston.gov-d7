<?php
/**
 * @file
 * bos_components_sidebar.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_components_sidebar_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-sidebar_item-field_sidebar_text'.
  $field_instances['paragraphs_item-sidebar_item-field_sidebar_text'] = array(
    'bundle' => 'sidebar_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the text for the sidebar item.',
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
    'field_name' => 'field_sidebar_text',
    'label' => 'Sidebar Text',
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

  // Exported field_instance: 'paragraphs_item-sidebar_item-field_title'.
  $field_instances['paragraphs_item-sidebar_item-field_title'] = array(
    'bundle' => 'sidebar_item',
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
    'label' => 'Sidebar Title',
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

  // Exported field_instance:
  // 'paragraphs_item-sidebar_item_w_icon-field_sidebar_icon'.
  $field_instances['paragraphs_item-sidebar_item_w_icon-field_sidebar_icon'] = array(
    'bundle' => 'sidebar_item_w_icon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select from the list an icon for the sidebar item.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
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
    'field_name' => 'field_sidebar_icon',
    'label' => 'Sidebar Icon',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-sidebar_item_w_icon-field_sidebar_text'.
  $field_instances['paragraphs_item-sidebar_item_w_icon-field_sidebar_text'] = array(
    'bundle' => 'sidebar_item_w_icon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the text for the sidebar item.',
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
    'field_name' => 'field_sidebar_text',
    'label' => 'Sidebar Text',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-sidebar_item_w_icon-field_title'.
  $field_instances['paragraphs_item-sidebar_item_w_icon-field_title'] = array(
    'bundle' => 'sidebar_item_w_icon',
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
    'field_name' => 'field_title',
    'label' => 'Sidebar Title',
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

  // Exported field_instance:
  // 'paragraphs_item-social_media_links-field_social_media_link'.
  $field_instances['paragraphs_item-social_media_links-field_social_media_link'] = array(
    'bundle' => 'social_media_links',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add social media links here.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
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
      'separated_title' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_social_media_link',
    'label' => 'Social Media Link',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'commission_contact_info' => -1,
        'document' => -1,
        'external_link' => -1,
        'featured_item' => -1,
        'featured_topics' => -1,
        'feedback' => -1,
        'group_of_links_grid' => -1,
        'header_text' => -1,
        'hero_image' => -1,
        'internal_link' => -1,
        'list' => -1,
        'photo' => -1,
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => 'social_networking',
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
        'sidebar_item' => 15,
        'sidebar_item_w_icon' => 16,
        'social_media_links' => 17,
        'social_networking' => 18,
        'text' => 19,
        'text_one_column' => 20,
        'text_three_column' => 21,
        'text_two_column' => 22,
        'transaction_grid' => 23,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-social_networking-field_external_link'.
  $field_instances['paragraphs_item-social_networking-field_external_link'] = array(
    'bundle' => 'social_networking',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please add the link and title for the social media item.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
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
    'field_name' => 'field_external_link',
    'label' => 'External Link',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-social_networking-field_social_icon'.
  $field_instances['paragraphs_item-social_networking-field_social_icon'] = array(
    'bundle' => 'social_networking',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select the icon for the social media link.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_social_icon',
    'label' => 'Social Icon',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add social media links here.');
  t('Enter the text for the sidebar item.');
  t('External Link');
  t('Please add the link and title for the social media item.');
  t('Please select the icon for the social media link.');
  t('Select from the list an icon for the sidebar item.');
  t('Sidebar Icon');
  t('Sidebar Text');
  t('Sidebar Title');
  t('Social Icon');
  t('Social Media Link');

  return $field_instances;
}
