<?php

/**
 * @file
 * Search settings.
 */
// Disable core search indexing.
$conf['search_cron_limit'] = 0;
$conf['search_active_modules'] = array(
  'apachesolr_search' => 'apachesolr_search',
  'file_entity' => 0,
  'node' => 0,
  'user' => 0,
);
$conf['search_default_module'] = 'apachesolr_search';

// Set search index to read-only by default.
$conf['apachesolr_environments']['acquia_search_server_1']['conf']['apachesolr_read_only'] = 1;
$conf['apachesolr_default_environment'] = 'acquia_search_server_1';

// If we're in the Acquia Cloud, require setting and set up a few variables.
if (!empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'prod':
      // Enable solr search.
      $conf['apachesolr_environments']['acquia_search_server_1']['conf']['apachesolr_read_only'] = 1;
      break;
  }
}
