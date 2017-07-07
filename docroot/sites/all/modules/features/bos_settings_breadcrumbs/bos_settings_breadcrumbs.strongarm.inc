<?php
/**
 * @file
 * bos_settings_breadcrumbs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_settings_breadcrumbs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_home_link_title';
  $strongarm->value = 'Home';
  $export['crumbs_home_link_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_minimum_trail_items';
  $strongarm->value = '2';
  $export['crumbs_minimum_trail_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_original_theme_breadcrumb';
  $strongarm->value = array(
    'boston' => 'boston_breadcrumb',
    'adminimal' => 'theme_breadcrumb',
    'seven' => 'theme_breadcrumb',
    'boston_admin' => 'theme_breadcrumb',
    'boston_hub' => 'boston_breadcrumb',
    'boston_public' => 'boston_breadcrumb',
  );
  $export['crumbs_original_theme_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_override_theme_breadcrumb';
  $strongarm->value = array(
    'theme_breadcrumb' => 'theme_breadcrumb',
    'boston_breadcrumb' => 0,
  );
  $export['crumbs_override_theme_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_separator';
  $strongarm->value = ' &gt; ';
  $export['crumbs_separator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_separator_span';
  $strongarm->value = 1;
  $export['crumbs_separator_span'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_show_current_page';
  $strongarm->value = '1';
  $export['crumbs_show_current_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_show_front_page';
  $strongarm->value = 1;
  $export['crumbs_show_front_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_weights';
  $strongarm->value = array(
    'path' => 1,
    'crumbs.home_title' => 2,
    '*' => 3,
  );
  $export['crumbs_weights'] = $strongarm;

  return $export;
}
