<?php
/**
 * @file
 * bos_component_vizwiz.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_vizwiz_paragraphs_info() {
  $items = array(
    'vizwiz' => array(
      'name' => 'VizWiz',
      'bundle' => 'vizwiz',
      'locked' => '1',
    ),
  );
  return $items;
}
