<?php
/**
 * @file
 * bos_workflow.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function bos_workflow_workbench_scheduler_export_schedules() {
  $items = array(
    'schedule' => array(
      'name' => 'schedule',
      'label' => 'Schedule',
      'start_state' => 'published',
      'end_state' => 'unpublished',
      'types' => array(
        0 => 'article',
        1 => 'department_profile',
        2 => 'event',
        3 => 'how_to',
        4 => 'landing_page',
        5 => 'listing_page',
        6 => 'person_profile',
        7 => 'place_profile',
        8 => 'post',
        9 => 'program_initiative_profile',
        10 => 'topic_page',
        11 => 'emergency_alert',
        12 => 'site_alert',
      ),
    ),
  );
  return $items;
}
