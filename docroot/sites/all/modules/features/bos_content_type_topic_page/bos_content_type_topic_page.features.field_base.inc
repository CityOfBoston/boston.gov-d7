<?php
/**
 * @file
 * bos_content_type_topic_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_content_type_topic_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_topic_category'.
  $field_bases['field_topic_category'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topic_category',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 1,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'topic_category' => 'topic_category',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
