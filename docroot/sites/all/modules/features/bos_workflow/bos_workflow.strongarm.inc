<?php
/**
 * @file
 * bos_workflow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bos_workflow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_myworkbench_disabled';
  $strongarm->value = FALSE;
  $export['workbench_myworkbench_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_scheduler_how_to';
  $strongarm->value = array(
    0 => 'workbench_scheduler_limit_current_revision',
  );
  $export['workbench_scheduler_how_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_scheduler_program_initiative_profile';
  $strongarm->value = array(
    0 => 'workbench_scheduler_limit_current_revision',
  );
  $export['workbench_scheduler_program_initiative_profile'] = $strongarm;

  return $export;
}
