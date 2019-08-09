<?php
/**
 * @file
 * bos_meta_tags.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_meta_tags_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__article';
  $strongarm->value = 1;
  $export['metatag_enable_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__event';
  $strongarm->value = 1;
  $export['metatag_enable_node__event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__how_to';
  $strongarm->value = 1;
  $export['metatag_enable_node__how_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__person_profile';
  $strongarm->value = 1;
  $export['metatag_enable_node__person_profile'] = $strongarm;

  return $export;
}
