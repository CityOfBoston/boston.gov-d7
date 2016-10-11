<?php
/**
 * @file
 * bos_subcomponents_recollect.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_subcomponents_recollect_paragraphs_info() {
  $items = array(
    'recollect_widget' => array(
      'name' => 'Recollect Widget',
      'bundle' => 'recollect_widget',
      'locked' => '1',
    ),
  );
  return $items;
}
