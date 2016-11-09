<?php
/**
 * @file
 * bos_vocabulary_contact.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_vocabulary_contact_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__contact';
  $strongarm->value = array(
    'view_modes' => array(
      'article' => array(
        'custom_settings' => TRUE,
      ),
      'contact' => array(
        'custom_settings' => TRUE,
      ),
      'department_listing' => array(
        'custom_settings' => TRUE,
      ),
      'popup_icon' => array(
        'custom_settings' => TRUE,
      ),
      'published_by' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'icon_popup' => array(
        'custom_settings' => TRUE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '40',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'name' => array(
          'weight' => '-5',
        ),
        'description' => array(
          'weight' => '-4',
        ),
      ),
      'display' => array(
        'description' => array(
          'department_listing' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'popup_icon' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'published_by' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'contact' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'article' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'icon_popup' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__contact'] = $strongarm;

  return $export;
}
