<?php
/**
 * @file
 * bos_vocabulary_maps_basemap.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_vocabulary_maps_basemap_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_basemap_url_'.
  $field_bases['field_basemap_url_'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basemap_url_',
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
