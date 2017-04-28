<?php
/**
 * @file
 * bos_components_sidebar.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bos_components_sidebar_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_sidebar_icon'.
  $field_bases['field_sidebar_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sidebar_icon',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'icon-alert' => 'Alert',
        'icon-document' => 'Document',
        'icon-email' => 'Email',
        'icon-event' => 'Event',
        'icon-form' => 'Form',
        'icon-location' => 'Location',
        'icon-payment' => 'Payment',
        'icon-phone' => 'Phone',
        'icon-time' => 'Time',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_sidebar_text'.
  $field_bases['field_sidebar_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sidebar_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_social_icon'.
  $field_bases['field_social_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_social_icon',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'icon-facebook' => 'Facebook',
        'icon-twitter' => 'Twitter',
        'icon-instagram' => 'Instagram',
        'icon-youtube' => 'Youtube',
        'icon-flickr' => 'Flickr',
        'icon-tumblr' => 'Tumblr',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
