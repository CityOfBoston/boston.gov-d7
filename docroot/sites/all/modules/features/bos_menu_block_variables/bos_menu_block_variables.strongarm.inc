<?php
/**
 * @file
 * bos_menu_block_variables.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_menu_block_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_ids';
  $strongarm->value = array(
    0 => 1,
    1 => 2,
  );
  $export['menu_block_ids'] = $strongarm;

  return $export;
}
