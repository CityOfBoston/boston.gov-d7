<?php
/**
 * @file
 * bos_vocabulary_maps_basemap.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_vocabulary_maps_basemap_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-maps_basemap-field_basemap_url_'.
  $field_instances['taxonomy_term-maps_basemap-field_basemap_url_'] = array(
    'bundle' => 'maps_basemap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_basemap_url_',
    'label' => 'Basemap (URL)',
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
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basemap (URL)');

  return $field_instances;
}
