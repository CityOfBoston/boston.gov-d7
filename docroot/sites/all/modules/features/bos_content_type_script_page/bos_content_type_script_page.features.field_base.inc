<?php
/**
 * @file
 * bos_content_type_script_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_content_type_script_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_embed_list'
  $field_bases['field_embed_list'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_embed_list',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
