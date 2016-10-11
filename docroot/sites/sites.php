<?php

/**
 * @file
 * Configuration file for Drupal's multi-site directory aliasing feature.
 *
 * This file allows you to define a set of aliases that map hostnames, ports, and
 * pathnames to configuration directories in the sites directory. These aliases
 * are loaded prior to scanning for directories, and they are exempt from the
 * normal discovery rules. See default.settings.php to view how Drupal discovers
 * the configuration directory when no alias is found.
 *
 * Aliases are useful on development servers, where the domain name may not be
 * the same as the domain of the live server. Since Drupal stores file paths in
 * the database (files, system table, etc.) this will ensure the paths are
 * correct when the site is deployed to a live server.
 *
 * To use this file, copy and rename it such that its path plus filename is
 * 'sites/sites.php'. If you don't need to use multi-site directory aliasing,
 * then you can safely ignore this file, and Drupal will ignore it too.
 *
 * Aliases are defined in an associative array named $sites. The array is
 * written in the format: '<port>.<domain>.<path>' => 'directory'. As an
 * example, to map www.drupal.org:8080/mysite/test to the configuration
 * directory sites/example.com, the array should be defined as:
 * @code
 * $sites = array(
 *   '8080.www.drupal.org.mysite.test' => 'example.com',
 * );
 * @endcode
 * The URL, www.drupal.org:8080/mysite/test/, could be a symbolic link or
 * an Apache Alias directive that points to the Drupal root containing
 * index.php. An alias could also be created for a subdomain. See the
 * @link drupal.org/documentation/install online Drupal installation guide @endlink
 * for more information on setting up domains, subdomains, and subdirectories.
 *
 * The following examples look for a site configuration in sites/example.com:
 * @code
 * URL: dev.drupal.org
 * $sites['dev.drupal.org'] = 'example.com';
 *
 * URL: localhost/example
 * $sites['localhost.example'] = 'example.com';
 *
 * URL: localhost:8080/example
 * $sites['8080.localhost.example'] = 'example.com';
 *
 * URL: www.drupal.org:8080/mysite/test/
 * $sites['8080.www.drupal.org.mysite.test'] = 'example.com';
 * @endcode
 *
 * @see default.settings.php
 * @see conf_path()
 * @see drupal.org/documentation/install/multi-site
 */

$sites['thehub.prod.acquia-sites.com'] = 'hub';
$sites['thehubci.prod.acquia-sites.com'] = 'hub';
$sites['thehubdev.prod.acquia-sites.com'] = 'hub';
$sites['thehubra.prod.acquia-sites.com'] = 'hub';
$sites['thehubstg.prod.acquia-sites.com'] = 'hub';
$sites['thehubuat.prod.acquia-sites.com'] = 'hub';

// Edit Domains for the hub.
$sites['edit-hub.boston.gov'] = 'hub';
$sites['edit-ci-hub.boston.gov'] = 'hub';
$sites['edit-dev-hub.boston.gov'] = 'hub';
$sites['edit-stg-hub.boston.gov'] = 'hub';
$sites['edit-uat-hub.boston.gov'] = 'hub';

// Domains for the hub.
$sites['hub.boston.gov'] = 'hub';
$sites['hub-ci.boston.gov'] = 'hub';
$sites['hub-dev.boston.gov'] = 'hub';
$sites['hub-stg.boston.gov'] = 'hub';
$sites['hub-uat.boston.gov'] = 'hub';

// Site settings for `drush runserver` for automated tests.
// @see build/custom/phing/build.yml, behat.server-url
// @see build/custom/phing/hub.yml, behat.server-url
// @see tests/behat/example.local.yml
// @see sites/default/settings/default.local.settings.php
// @see sites/hub/settings/default.local.settings.php
$sites['8888.127.0.0.1'] = 'default';
$sites['8889.127.0.0.1'] = 'hub';

if (file_exists(__DIR__ . '/local.sites.php')) {
  require __DIR__ . '/local.sites.php';
}
