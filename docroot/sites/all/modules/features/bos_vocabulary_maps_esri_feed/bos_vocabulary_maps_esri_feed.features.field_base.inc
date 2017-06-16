<?php
/**
 * @file
 * bos_vocabulary_maps_esri_feed.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_vocabulary_maps_esri_feed_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_map_default_coordinates'
  $field_bases['field_map_default_coordinates'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_map_default_coordinates',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  // Exported field_base: 'field_map_esri_feed'
  $field_bases['field_map_esri_feed'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_map_esri_feed',
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
