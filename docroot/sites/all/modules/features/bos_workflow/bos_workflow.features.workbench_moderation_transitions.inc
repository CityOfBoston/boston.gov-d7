<?php
/**
 * @file
 * bos_workflow.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function bos_workflow_workbench_moderation_export_transitions() {
  $items = array(
    'archive:draft' => array(
      'from_name' => 'archive',
      'to_name' => 'draft',
      'name' => 'Draft from Archived',
    ),
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
    'published:archive' => array(
      'from_name' => 'published',
      'to_name' => 'archive',
      'name' => 'Archived',
    ),
    'published:draft' => array(
      'from_name' => 'published',
      'to_name' => 'draft',
      'name' => 'Draft from Published',
    ),
  );
  return $items;
}
