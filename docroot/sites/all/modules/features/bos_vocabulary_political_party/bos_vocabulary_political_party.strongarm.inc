<?php
/**
 * @file
 * bos_vocabulary_political_party.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_vocabulary_political_party_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_political_party_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_political_party_pattern'] = $strongarm;

  return $export;
}
