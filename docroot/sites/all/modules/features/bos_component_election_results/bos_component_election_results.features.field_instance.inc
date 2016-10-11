<?php
/**
 * @file
 * bos_component_election_results.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_election_results_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-election_results-field_source_url'.
  $field_instances['paragraphs_item-election_results-field_source_url'] = array(
    'bundle' => 'election_results',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is where the election results live. ',
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
    'field_name' => 'field_source_url',
    'label' => 'Source URL',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Source URL');
  t('This is where the election results live. ');

  return $field_instances;
}
