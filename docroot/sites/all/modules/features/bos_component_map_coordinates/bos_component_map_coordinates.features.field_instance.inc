<?php
/**
 * @file
 * bos_component_map_coordinates.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_map_coordinates_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-map_coordinates-field_map_latitude'.
  $field_instances['paragraphs_item-map_coordinates-field_map_latitude'] = array(
    'bundle' => 'map_coordinates',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the North/South coordinates. Example: Boston City Hall Latitude is 42.3604.',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
    ),
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_map_latitude',
    'label' => 'Latitude',
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

  // Exported field_instance:
  // 'paragraphs_item-map_coordinates-field_map_longitude'.
  $field_instances['paragraphs_item-map_coordinates-field_map_longitude'] = array(
    'bundle' => 'map_coordinates',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the East/West coordinates. Example: Boston City Hall is -71.0580.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_map_longitude',
    'label' => 'Longitude',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-map_coordinates-field_map_zoom'.
  $field_instances['paragraphs_item-map_coordinates-field_map_zoom'] = array(
    'bundle' => 'map_coordinates',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a number between 1 (zoomed all the way out) and 18 (zoomed all the way in).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_map_zoom',
    'label' => 'Zoom',
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
  t('Enter a number between 1 (zoomed all the way out) and 18 (zoomed all the way in).');
  t('Enter the East/West coordinates. Example: Boston City Hall is -71.0580.');
  t('Enter the North/South coordinates. Example: Boston City Hall Latitude is 42.3604.');
  t('Latitude');
  t('Longitude');
  t('Zoom');

  return $field_instances;
}
