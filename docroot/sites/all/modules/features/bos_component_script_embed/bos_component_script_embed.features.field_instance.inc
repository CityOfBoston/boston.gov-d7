<?php
/**
 * @file
 * bos_component_script_embed.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_component_script_embed_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-script_embed-field_source_url'.
  $field_instances['paragraphs_item-script_embed-field_source_url'] = array(
    'bundle' => 'script_embed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will be the source of the script embed.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
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
    'format' => 'script_source_url',
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

  // Exported field_instance: 'paragraphs_item-script_embed-field_sticky'.
  $field_instances['paragraphs_item-script_embed-field_sticky'] = array(
    'bundle' => 'script_embed',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Should this load asynchronously?',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
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
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_sticky',
    'label' => 'Async?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Async?');
  t('Should this load asynchronously?');
  t('Source URL');
  t('This will be the source of the script embed.');

  return $field_instances;
}
