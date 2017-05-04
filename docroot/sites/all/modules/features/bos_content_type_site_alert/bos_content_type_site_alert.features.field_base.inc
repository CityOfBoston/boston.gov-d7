<?php
/**
 * @file
 * bos_content_type_site_alert.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_content_type_site_alert_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_excluded_nodes'.
  $field_bases['field_excluded_nodes'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_excluded_nodes',
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
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'article' => 'article',
          'event' => 'event',
          'how_to' => 'how_to',
          'landing_page' => 'landing_page',
          'listing_page' => 'listing_page',
          'program_initiative_profile' => 'program_initiative_profile',
          'public_notice' => 'public_notice',
          'script_page' => 'script_page',
          'tabbed_content' => 'tabbed_content',
          'topic_page' => 'topic_page',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'title_field'.
  $field_bases['title_field'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'title_field',
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
    'translatable' => 1,
    'type' => 'text',
  );

  return $field_bases;
}
