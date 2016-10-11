<?php

/**
 * @file
 * File settings.
 */
// In Acquia cloud, this file path is symlinked to the correct server dir.
$conf['file_public_path'] = 'sites/default/files';

// We write composer.json to sites/all/vendor so that it is under VCS,
// as per Composer's best practices.
// @see https://getcomposer.org/doc/01-basic-usage.md#composer-lock-the-lock-file
$conf['composer_manager_file_dir'] = 'sites/all';

// We do NOT put it at the repo root because we do not want composer_manager
// to overwrite the manually mantained composer.json (for automated testing)
// that lives there. This is not a best practice. It's either this, or register
// dependencies at /composer.json with Drupal via a module.
$conf['composer_manager_vendor_dir'] = 'sites/all/vendor';

if (!empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  // File directories.
  $conf['file_private_path'] = '/mnt/files/' . $_ENV['AH_SITE_NAME'] . '/files-private';
  $conf['file_temporary_path'] = '/mnt/tmp/' . $_ENV['AH_SITE_NAME'];

  // When we're on the Acquia Cloud, we won't have write access to
  // sites/all/vendor, so we disable auto-generation.
  $conf['composer_manager_autobuild_file'] = 0;
  $conf['composer_manager_autobuild_packages'] = 0;
}
// Settings for local development.
else {
  // Enable composer_manager autobuilds.
  $conf['composer_manager_autobuild_file'] = 1;
  $conf['composer_manager_autobuild_packages'] = 1;
}
