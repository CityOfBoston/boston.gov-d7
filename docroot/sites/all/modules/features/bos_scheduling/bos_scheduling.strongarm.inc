<?php
/**
 * @file
 * bos_scheduling.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_scheduling_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_scheduler_settings_published_revisions';
  $strongarm->value = 1;
  $export['workbench_scheduler_settings_published_revisions'] = $strongarm;

  return $export;
}
