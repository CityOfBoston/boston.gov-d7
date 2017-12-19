<?php
/**
 * @file
 * bos_vocabulary_massachusetts_general_law.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_vocabulary_massachusetts_general_law_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_massachusetts_general_law';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_massachusetts_general_law'] = $strongarm;

  return $export;
}
