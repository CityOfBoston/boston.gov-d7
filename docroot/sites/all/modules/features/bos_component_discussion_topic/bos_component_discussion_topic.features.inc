<?php
/**
 * @file
 * bos_component_discussion_topic.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_discussion_topic_paragraphs_info() {
  $items = array(
    'discussion_topic' => array(
      'name' => 'Discussion Topic',
      'bundle' => 'discussion_topic',
      'locked' => '1',
    ),
  );
  return $items;
}
