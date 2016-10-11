<?php

/**
 * @file
 * Cron settings.
 */
// Disable acquia_spi by default.
$conf['acquia_spi_use_cron'] = FALSE;

// If we're in the Acquia Cloud, require setting and set up a few variables.
if (!empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'prod':
      // Disable automatic cron run.
      $conf['cron_safe_threshold'] = 0;
      $conf['acquia_spi_use_cron'] = TRUE;

      break;
  }
}
