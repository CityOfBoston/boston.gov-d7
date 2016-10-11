<?php
/**
 * @file
 * hub_context_search_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hub_context_search_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hub_search_blocks';
  $context->description = 'Hub search blocks';
  $context->tag = 'hub';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/site/*' => 'search/site/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-KDCBPvuidlfD00604jKWQA89mHFb41Lk' => array(
          'module' => 'facetapi',
          'delta' => 'KDCBPvuidlfD00604jKWQA89mHFb41Lk',
          'region' => 'content',
          'weight' => '9',
        ),
        'facetapi-iLOyHjPah8Jtd2iAJv073e4vtVtL4H8i' => array(
          'module' => 'facetapi',
          'delta' => 'iLOyHjPah8Jtd2iAJv073e4vtVtL4H8i',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hub search blocks');
  t('hub');
  $export['hub_search_blocks'] = $context;

  return $export;
}
