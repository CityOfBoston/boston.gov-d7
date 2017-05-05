<?php
/**
 * @file
 * bos_component_newsletter.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_component_newsletter_paragraphs_info() {
  $items = array(
    'newsletter' => array(
      'name' => 'Newsletter',
      'bundle' => 'newsletter',
      'locked' => '1',
    ),
  );
  return $items;
}
