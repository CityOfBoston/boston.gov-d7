<?php
/**
 * @file
 * bos_file_type_document.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_file_type_document_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_file_action_document';
  $strongarm->value = '2';
  $export['rh_file_action_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_file_override_document';
  $strongarm->value = 0;
  $export['rh_file_override_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_file_redirect_document';
  $strongarm->value = '';
  $export['rh_file_redirect_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_file_redirect_response_document';
  $strongarm->value = '301';
  $export['rh_file_redirect_response_document'] = $strongarm;

  return $export;
}
