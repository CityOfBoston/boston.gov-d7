<?php
/**
 * @file
 * bos_subcomponents_seamless_doc.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_subcomponents_seamless_doc_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-seamless_doc-field_document_id'.
  $field_instances['paragraphs_item-seamless_doc-field_document_id'] = array(
    'bundle' => 'seamless_doc',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the seamless document ID for this page. Example: http://example.com/s/da3e1eb84d96dad57400afecea6ececa/embed/iframe, the id is the random string of letters & numbers.
',
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
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_document_id',
    'label' => 'Document ID',
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Document ID');
  t('Enter the seamless document ID for this page. Example: http://example.com/s/da3e1eb84d96dad57400afecea6ececa/embed/iframe, the id is the random string of letters & numbers.
');

  return $field_instances;
}
