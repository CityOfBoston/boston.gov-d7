<?php

/**
 * @file
 * Cache settings.
 */

if (!empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'prod':

      // Enforce caching in production.
      $conf['cache'] = TRUE;

      // When using varnish, set cache_lifetime to 0.
      // @see https://backlog.acquia.com/browse/NN-7868 and
      // https://confluence.acquia.com/display/support/Caching+Bible
      // Setting this to 0 allows direct cache clears to clear caches that
      // have not yet reached expiration.
      // Sites with large amounts of content creation/edits could benefit from
      // setting this to a non-zero value as it impacts the block cache as well.
      $conf['cache_lifetime'] = 0;

      // Set default cache expiration to 5 minutes.
      $conf['page_cache_maximum_age'] = 300;

      $conf['block_cache'] = TRUE;
      // Allows Block to be cached on sites with hook_node_grant() implementations
      // $conf['block_cache_bypass_node_grants'] = TRUE;
      // Enforce aggregation and compression.
      //$conf['page_compression'] = TRUE;
      //$conf['preprocess_css'] = TRUE;
      //$conf['preprocess_js'] = TRUE;

      // Production will always be 100% HTTPS, so, we should never need to purge
      // HTTP URLs so we disable it here to optimize.
      $conf['acquia_purge_http'] = FALSE;

      break;
  }

  // When we are in Acquia environments, always purge HTTPS URLs.
  $conf['acquia_purge_https'] = TRUE;

  // Acquia Purge should run at regular intervals, so enable cron.
  $conf['acquia_purge_cron'] = TRUE;

  // Memcache for caching on Acquia Cloud.
  $conf['cache_backends'][] = $module_dir . '/contrib/memcache/memcache.inc';
  $conf['lock_inc'] = $module_dir . '/contrib/memcache/memcache-lock.inc';
  $conf['memcache_stampede_protection'] = TRUE;
  $conf['cache_default_class'] = 'MemCacheDrupal';

  // Memcache stampede protection can be disabled for entire bins, specific cid's
  // in specific bins, or cid's starting with a specific prefix in specific bins.
  // see: https://www.drupal.org/node/2419757
  $conf['memcache_stampede_protection_ignore'] = array(
      // Ignore some cids in 'cache_bootstrap'.
    'cache_bootstrap' => array(
      'module_implements',
      'variables',
      'lookup_cache',
      'schema:runtime:*',
      'theme_registry:runtime:*',
    ),
      // Ignore all cids in the 'cache' bin starting with 'i18n:string:'
    'cache' => array(
      'i18n:string:*',
    ),
      // Disable stampede protection for the entire 'cache_path' and 'cache_rules'
      // bins.
    'cache_path',
    'cache_rules',
      // Ignore stampede protection for cache_views because of delayed cache_set.
    'cache_views',
    'cache_entity_paragraphs_item',
  );

  // The 'cache_form' bin must be assigned to non-volatile storage.
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

  // Cache bins that often grow too large to keep in memcache
  // $conf['cache_class_cache_entity_bean'] = 'DrupalDatabaseCache';
  // $conf['cache_class_cache_entity_comment'] = 'DrupalDatabaseCache';
  // $conf['cache_class_cache_entity_file'] = 'DrupalDatabaseCache';
  // $conf['cache_class_cache_entity_node'] = 'DrupalDatabaseCache';
  // $conf['cache_class_cache_block'] = 'DrupalDatabaseCache';
  // $conf['cache_class_cache_views']      = 'DrupalDatabaseCache';
  // $conf['cache_class_cache_views_data'] = 'DrupalDatabaseCache';
  // Don't bootstrap the database when serving pages from the cache.
  // With the page cache disabled, no sense invoking hooks. Note that this is
  // NOT compatible with domain access.
  $conf['page_cache_without_database'] = TRUE;
  $conf['page_cache_invoke_hooks'] = FALSE;

  // Varnish and page caching are fundamentally the same. In all SSL through
  // Varnish backed environments (all Acquia envs), disable the page cache.
  // @See https://backlog.acquia.com/browse/DOC-2961
  $conf['cache_backends'][] = 'includes/cache-install.inc';
  $conf['cache_class_cache_page'] = 'DrupalFakeCache';

  // Even though our page cache backend is fake, setting redirects to be
  // stored in the page cache will set the appropriate cache headers.
  $conf['redirect_page_cache'] = TRUE;
}
