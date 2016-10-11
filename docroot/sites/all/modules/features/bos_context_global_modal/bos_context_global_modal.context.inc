<?php
/**
 * @file
 * bos_context_global_modal.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bos_context_global_modal_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bos_context_global_modal';
  $context->description = 'Place blocks in the modal region.';
  $context->tag = 'modal';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bos_pilot_blocks-feedback' => array(
          'module' => 'bos_pilot_blocks',
          'delta' => 'feedback',
          'region' => 'modal',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks in the modal region.');
  t('modal');
  $export['bos_context_global_modal'] = $context;

  return $export;
}
