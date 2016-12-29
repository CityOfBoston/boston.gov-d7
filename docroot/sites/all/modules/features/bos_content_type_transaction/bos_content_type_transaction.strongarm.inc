<?php
/**
 * @file
 * bos_content_type_transaction.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_content_type_transaction_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_transaction';
  $strongarm->value = 0;
  $export['comment_anonymous_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_transaction';
  $strongarm->value = 1;
  $export['comment_default_mode_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_transaction';
  $strongarm->value = '50';
  $export['comment_default_per_page_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_transaction';
  $strongarm->value = 1;
  $export['comment_form_location_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_transaction';
  $strongarm->value = '1';
  $export['comment_preview_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_transaction';
  $strongarm->value = 1;
  $export['comment_subject_field_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_transaction';
  $strongarm->value = '0';
  $export['comment_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__transaction';
  $strongarm->value = array(
    'view_modes' => array(
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'article' => array(
        'custom_settings' => FALSE,
      ),
      'calendar_listing' => array(
        'custom_settings' => FALSE,
      ),
      'contact' => array(
        'custom_settings' => FALSE,
      ),
      'department_listing' => array(
        'custom_settings' => FALSE,
      ),
      'featured_item' => array(
        'custom_settings' => FALSE,
      ),
      'featured_topics' => array(
        'custom_settings' => FALSE,
      ),
      'listing_short' => array(
        'custom_settings' => FALSE,
      ),
      'listing_long' => array(
        'custom_settings' => FALSE,
      ),
      'poll_stub' => array(
        'custom_settings' => FALSE,
      ),
      'popup_icon' => array(
        'custom_settings' => FALSE,
      ),
      'published_by' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'rabbit_hole' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_transaction';
  $strongarm->value = array();
  $export['menu_options_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_transaction';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_transaction';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_transaction';
  $strongarm->value = '1';
  $export['node_preview_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_transaction';
  $strongarm->value = 0;
  $export['node_submitted_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_transaction';
  $strongarm->value = 'rh_node';
  $export['rh_module_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_transaction';
  $strongarm->value = '2';
  $export['rh_node_action_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_override_transaction';
  $strongarm->value = 0;
  $export['rh_node_override_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_response_transaction';
  $strongarm->value = '301';
  $export['rh_node_redirect_response_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_transaction';
  $strongarm->value = '';
  $export['rh_node_redirect_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_transaction';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_transaction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_transaction';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.8',
  );
  $export['xmlsitemap_settings_node_transaction'] = $strongarm;

  return $export;
}
