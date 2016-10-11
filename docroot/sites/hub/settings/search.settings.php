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

// Settings for Acquia Cloud Search on local
if (empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  $_ENV['AH_SITE_NAME'] = 'thehub';
  $_ENV['AH_SITE_ENVIRONMENT'] = 'dev';
}