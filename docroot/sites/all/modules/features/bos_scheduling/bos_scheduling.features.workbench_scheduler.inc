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
        2 => 'event',
        3 => 'how_to',
        4 => 'landing_page',
        5 => 'listing_page',
        6 => 'post',
        7 => 'script_page',
        8 => 'tabbed_content',
        9 => 'topic_page',
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
        2 => 'event',
        3 => 'how_to',
        4 => 'landing_page',
        5 => 'listing_page',
        6 => 'post',
        7 => 'script_page',
        8 => 'tabbed_content',
        9 => 'topic_page',
      ),
      'from_name' => 'published',
      'to_name' => 'draft',
    ),
  );
  return $items;
}
