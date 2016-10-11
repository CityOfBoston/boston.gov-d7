<?php
/**
 * @file
 * hub_context_global_header.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hub_context_global_header_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hub_context_global_header';
  $context->description = 'Place blocks in header region for Hub site.';
  $context->tag = 'menus';
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
        'hub_blocks-search' => array(
          'module' => 'hub_blocks',
          'delta' => 'search',
          'region' => 'header',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks in header region for Hub site.');
  t('menus');
  $export['hub_context_global_header'] = $context;

  return $export;
}
