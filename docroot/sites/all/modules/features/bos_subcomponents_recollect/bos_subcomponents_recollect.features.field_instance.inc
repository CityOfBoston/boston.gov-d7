<?php
/**
 * @file
 * bos_subcomponents_recollect.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bos_subcomponents_recollect_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-recollect_widget-field_short_description'.
  $field_instances['paragraphs_item-recollect_widget-field_short_description'] = array(
    'bundle' => 'recollect_widget',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optional description text for the Recollect widget. ',
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
    'field_name' => 'field_short_description',
    'label' => 'Short Description',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Optional description text for the Recollect widget. ');
  t('Short Description');

  return $field_instances;
}
