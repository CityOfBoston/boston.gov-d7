<?php
/**
 * @file
 * bos_scheduling.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function bos_scheduling_workbench_scheduler_export_schedules() {
  $items = array(
    'schedule' => array(
      'name' => 'schedule',
      'label' => 'Publish',
      'types' => array(
        0 => 'article',
        1 => 'department_profile',
        2 => 'emergency_alert',
        3 => 'event',
        4 => 'how_to',
        5 => 'landing_page',
        6 => 'listing_page',
        7 => 'person_profile',
        8 => 'place_profile',
        9 => 'post',
        10 => 'program_initiative_profile',
        11 => 'public_notice',
        12 => 'script_page',
        13 => 'site_alert',
        14 => 'tabbed_content',
        15 => 'topic_page',
      ),
      'from_name' => 'needs_review',
      'to_name' => 'published',
    ),
    'unpublish' => array(
      'name' => 'unpublish',
      'label' => 'Unpublish',
      'types' => array(
        0 => 'article',
        1 => 'department_profile',
        2 => 'emergency_alert',
        3 => 'event',
        4 => 'how_to',
        5 => 'landing_page',
        6 => 'listing_page',
        7 => 'person_profile',
        8 => 'place_profile',
        9 => 'post',
        10 => 'program_initiative_profile',
        11 => 'public_notice',
        12 => 'script_page',
        13 => 'site_alert',
        14 => 'tabbed_content',
        15 => 'topic_page',
      ),
      'from_name' => 'published',
      'to_name' => 'draft',
    ),
  );
  return $items;
}
