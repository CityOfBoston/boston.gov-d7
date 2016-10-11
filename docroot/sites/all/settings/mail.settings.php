<?php

/**
 * @file
 * Mail settings.
 */
// Disable mail on non-production enviroments.
if (!isset($_ENV['AH_SITE_ENVIRONMENT']) || !in_array($_ENV['AH_SITE_ENVIRONMENT'], array('prod'))) {
  // Ensure DevelMailLog is available even if Devel module is disabled.
  include_once 'includes/mail.inc';
  include_once 'modules/system/system.mail.inc';
  include_once $module_dir . '/development/devel/devel.mail.inc';

  $conf['mail_system'] = array(
    'default-system' => 'DevelMailLog',
  );
}
