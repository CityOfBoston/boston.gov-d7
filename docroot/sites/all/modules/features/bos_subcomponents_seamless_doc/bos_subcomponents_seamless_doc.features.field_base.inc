<?php
/**
 * @file
 * bos_subcomponents_seamless_doc.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_subcomponents_seamless_doc_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_document_id'.
  $field_bases['field_document_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_document_id',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
