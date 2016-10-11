<?php
/**
 * @file
 * bos_workflow.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function bos_workflow_workbench_moderation_export_states() {
  $items = array(
    'archive' => array(
      'name' => 'archive',
      'label' => 'Archive',
      'description' => 'Content is archived',
      'weight' => -7,
    ),
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => -10,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Ready for moderation',
      'weight' => 0,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => -8,
    ),
  );
  return $items;
}
