<?php
/**
 * @file
 * bos_subcomponents_seamless_doc.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function bos_subcomponents_seamless_doc_paragraphs_info() {
  $items = array(
    'seamless_doc' => array(
      'name' => 'Seamless Doc',
      'bundle' => 'seamless_doc',
      'locked' => '1',
    ),
  );
  return $items;
}
