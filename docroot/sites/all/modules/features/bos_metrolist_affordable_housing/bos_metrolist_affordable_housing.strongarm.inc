<?php
/**
 * @file
 * bos_metrolist_affordable_housing.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_metrolist_affordable_housing_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_metrolist_affordable_housing';
  $strongarm->value = 'edit-rabbit-hole';
  $export['additional_settings__active_tab_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_metrolist_affordable_housing';
  $strongarm->value = 0;
  $export['comment_anonymous_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_metrolist_affordable_housing';
  $strongarm->value = 1;
  $export['comment_default_mode_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_metrolist_affordable_housing';
  $strongarm->value = '50';
  $export['comment_default_per_page_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_metrolist_affordable_housing';
  $strongarm->value = 1;
  $export['comment_form_location_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_metrolist_affordable_housing';
  $strongarm->value = '1';
  $export['comment_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_metrolist_affordable_housing';
  $strongarm->value = '1';
  $export['comment_preview_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_metrolist_affordable_housing';
  $strongarm->value = 1;
  $export['comment_subject_field_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__metrolist_affordable_housing';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'rabbit_hole' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '19',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_metrolist_affordable_housing';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_metrolist_affordable_housing';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_metrolist_affordable_housing';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_metrolist_affordable_housing';
  $strongarm->value = '1';
  $export['node_preview_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_metrolist_affordable_housing';
  $strongarm->value = 1;
  $export['node_submitted_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'redirect_setting_name_metrolist_affordable_housing';
  $strongarm->value = 'rh_node_redirect';
  $export['redirect_setting_name_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_metrolist_affordable_housing';
  $strongarm->value = 'rh_node';
  $export['rh_module_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_metrolist_affordable_housing';
  $strongarm->value = '3';
  $export['rh_node_action_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_override_metrolist_affordable_housing';
  $strongarm->value = 0;
  $export['rh_node_override_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_metrolist_affordable_housing';
  $strongarm->value = '/metrolist/affordable-properties?combine=[node:field_mah_address]';
  $export['rh_node_redirect_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_response_metrolist_affordable_housing';
  $strongarm->value = '301';
  $export['rh_node_redirect_response_metrolist_affordable_housing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_metrolist_affordable_housing';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_metrolist_affordable_housing'] = $strongarm;

  return $export;
}
