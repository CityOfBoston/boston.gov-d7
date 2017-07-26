<?php
/**
 * @file
 * bos_vocabulary_newsletters.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_vocabulary_newsletters_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-newsletters-field_id'.
  $field_instances['taxonomy_term-newsletters-field_id'] = array(
    'bundle' => 'newsletters',
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
    'field_name' => 'field_id',
    'label' => 'ID',
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
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ID');

  return $field_instances;
}
