<?php
/**
 * @file
 * hub_user_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hub_user_fields_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_application_id_list'.
  $field_instances['user-user-field_application_id_list'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a comma separated list of Application IDs.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_application_id_list',
    'label' => 'Application ID List',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => 0,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 52,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Application ID List');
  t('Enter a comma separated list of Application IDs.');

  return $field_instances;
}
