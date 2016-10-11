<?php
/**
 * @file
 * bos_vocabulary_icons.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_vocabulary_icons_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_action_icons';
  $strongarm->value = '2';
  $export['rh_taxonomy_term_action_icons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_override_icons';
  $strongarm->value = 0;
  $export['rh_taxonomy_term_override_icons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_icons';
  $strongarm->value = '';
  $export['rh_taxonomy_term_redirect_icons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_response_icons';
  $strongarm->value = '301';
  $export['rh_taxonomy_term_redirect_response_icons'] = $strongarm;

  return $export;
}
