<?php
/**
 * @file
 * bos_picture_breakpoints.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_picture_breakpoints_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'breakpoints_multipliers';
  $strongarm->value = array(
    '1x' => '1x',
    '1.5x' => '1.5x',
    '2x' => '2x',
  );
  $export['breakpoints_multipliers'] = $strongarm;

  return $export;
}
