<?php
/**
 * @file
 * bos_development.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bos_development_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'developer_blocks';
  $context->description = 'Blocks added to pages for development purposes.';
  $context->tag = 'development';
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
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'modal',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks added to pages for development purposes.');
  t('development');
  $export['developer_blocks'] = $context;

  return $export;
}
