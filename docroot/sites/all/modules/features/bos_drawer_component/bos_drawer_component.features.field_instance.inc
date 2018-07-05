<?php
/**
 * @file
 * bos_drawer_component.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_drawer_component_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-drawer-field_short_description'.
  $field_instances['paragraphs_item-drawer-field_short_description'] = array(
    'bundle' => 'drawer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
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
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_short_description',
    'label' => 'Short Description',
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

  // Exported field_instance: 'paragraphs_item-drawer-field_text_blocks'.
  $field_instances['paragraphs_item-drawer-field_text_blocks'] = array(
    'bundle' => 'drawer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the content that will display in the drawer.',
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
    'field_name' => 'field_text_blocks',
    'label' => 'Text Blocks',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        '3_column_w_image' => -1,
        'cabinet' => -1,
        'commission_contact_info' => -1,
        'document' => -1,
        'drawer' => -1,
        'drawers' => -1,
        'external_link' => -1,
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
        'internal_link' => -1,
        'list' => -1,
        'news_announcements' => -1,
        'photo' => -1,
        'sidebar_item' => -1,
        'sidebar_item_w_icon' => -1,
        'social_media_links' => -1,
        'social_networking' => -1,
        'tabbed_content_tab' => -1,
        'text' => -1,
        'text_one_column' => 'text_one_column',
        'text_three_column' => 'text_three_column',
        'text_two_column' => 'text_two_column',
        'transaction_grid' => -1,
        'user_action' => -1,
      ),
      'bundle_weights' => array(
        '3_column_w_image' => -64,
        'cabinet' => -63,
        'document' => -62,
        'drawer' => -61,
        'drawers' => -60,
        'external_link' => -59,
        'featured_item' => -58,
        'featured_topics' => -57,
        'fyi' => -36,
        'gol_list_links' => -56,
        'grid_of_places' => -55,
        'grid_of_topics' => -54,
        'group_of_links_grid' => -53,
        'group_of_links_list' => -52,
        'header_text' => -51,
        'hero_image' => -50,
        'iframe' => -35,
        'internal_link' => -49,
        'list' => -48,
        'news_announcements' => -47,
        'photo' => -46,
        'sidebar_item' => -45,
        'sidebar_item_w_icon' => -44,
        'social_media_links' => -43,
        'social_networking' => -42,
        'tabbed_content_tab' => -34,
        'text' => -41,
        'text_one_column' => -40,
        'text_three_column' => -38,
        'text_two_column' => -39,
        'transaction_grid' => -37,
        'user_action' => -33,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-drawer-field_title'.
  $field_instances['paragraphs_item-drawer-field_title'] = array(
    'bundle' => 'drawer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Short Description');
  t('Text Blocks');
  t('This is the content that will display in the drawer.');
  t('Title');

  return $field_instances;
}
