<?php
/**
 * @file
 * bos_subcomponents_links.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_subcomponents_links_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-document-field_document'.
  $field_instances['paragraphs_item-document-field_document'] = array(
    'bundle' => 'document',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 1,
      ),
      'listing' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 1,
      ),
      'separated_title' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_url_plain',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_document',
    'label' => 'Document',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'document-file-[current-date:file_directory_storage_date]',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
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
          'document' => 'document',
          'image' => 0,
          'video' => 0,
        ),
        'browser_plugins' => array(
          'boston_media_browser_tabs--boston_media' => 0,
          'boston_media_browser_tabs--icons' => 0,
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-document-field_title'.
  $field_instances['paragraphs_item-document-field_title'] = array(
    'bundle' => 'document',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add an optional title to customize the download link text.',
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
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_title',
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

  // Exported field_instance:
  // 'paragraphs_item-external_link-field_external_link'.
  $field_instances['paragraphs_item-external_link-field_external_link'] = array(
    'bundle' => 'external_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'group_of_links' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_separate',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_separate',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_separate',
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
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'required',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-internal_link-field_internal_link'.
  $field_instances['paragraphs_item-internal_link-field_internal_link'] = array(
    'bundle' => 'internal_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'ribbon_link' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_internal_link',
    'label' => 'Internal Link',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => array(
          'active' => 0,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-internal_link-field_title'.
  $field_instances['paragraphs_item-internal_link-field_title'] = array(
    'bundle' => 'internal_link',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add an optional title to customize the link text.',
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'separated_title' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => '',
          'title_style' => '',
        ),
        'type' => 'title_linked',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add an optional title to customize the download link text.');
  t('Add an optional title to customize the link text.');
  t('Document');
  t('External Link');
  t('Internal Link');
  t('Title');

  return $field_instances;
}
