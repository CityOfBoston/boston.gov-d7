<?php
/**
 * @file
 * bos_context_global_footer.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bos_context_global_footer_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bos_context_global_footer';
  $context->description = 'Place blocks in the footer region.';
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
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks in the footer region.');
  t('menus');
  $export['bos_context_global_footer'] = $context;

  return $export;
}
