<?php
/**
 * @file
 * bos_vocabulary_holidays.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_vocabulary_holidays_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_action_holidays';
  $strongarm->value = '2';
  $export['rh_taxonomy_term_action_holidays'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_override_holidays';
  $strongarm->value = 0;
  $export['rh_taxonomy_term_override_holidays'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_holidays';
  $strongarm->value = '';
  $export['rh_taxonomy_term_redirect_holidays'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_taxonomy_term_redirect_response_holidays';
  $strongarm->value = '301';
  $export['rh_taxonomy_term_redirect_response_holidays'] = $strongarm;

  return $export;
}
