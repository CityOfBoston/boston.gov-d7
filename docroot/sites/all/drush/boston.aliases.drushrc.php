<?php

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site boston, environment ci
$aliases['ci'] = array(
  'root' => '/var/www/html/boston.ci/docroot',
  'ac-site' => 'boston',
  'ac-env' => 'ci',
  'ac-realm' => 'prod',
  'uri' => 'bostonci.prod.acquia-sites.com',
  'remote-host' => 'staging-15139.prod.hosting.acquia.com',
  'remote-user' => 'boston.ci',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['ci.livedev'] = array(
  'parent' => '@boston.ci',
  'root' => '/mnt/gfs/boston.ci/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site boston, environment dev
$aliases['dev'] = array(
  'root' => '/var/www/html/boston.dev/docroot',
  'ac-site' => 'boston',
  'ac-env' => 'dev',
  'ac-realm' => 'prod',
  'uri' => 'bostondev.prod.acquia-sites.com',
  'remote-host' => 'staging-15139.prod.hosting.acquia.com',
  'remote-user' => 'boston.dev',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['dev.livedev'] = array(
  'parent' => '@boston.dev',
  'root' => '/mnt/gfs/boston.dev/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site boston, environment prod
$aliases['prod'] = array(
  'root' => '/var/www/html/boston.prod/docroot',
  'ac-site' => 'boston',
  'ac-env' => 'prod',
  'ac-realm' => 'prod',
  'uri' => 'boston.prod.acquia-sites.com',
  'remote-host' => 'web-15135.prod.hosting.acquia.com',
  'remote-user' => 'boston.prod',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['prod.livedev'] = array(
  'parent' => '@boston.prod',
  'root' => '/mnt/gfs/boston.prod/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site boston, environment ra
$aliases['ra'] = array(
  'root' => '/var/www/html/boston.ra/docroot',
  'ac-site' => 'boston',
  'ac-env' => 'ra',
  'ac-realm' => 'prod',
  'uri' => 'bostonra.prod.acquia-sites.com',
  'remote-host' => 'staging-14794.prod.hosting.acquia.com',
  'remote-user' => 'boston.ra',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['ra.livedev'] = array(
  'parent' => '@boston.ra',
  'root' => '/mnt/gfs/boston.ra/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site boston, environment test
$aliases['test'] = array(
  'root' => '/var/www/html/boston.test/docroot',
  'ac-site' => 'boston',
  'ac-env' => 'test',
  'ac-realm' => 'prod',
  'uri' => 'bostonstg.prod.acquia-sites.com',
  'remote-host' => 'staging-15139.prod.hosting.acquia.com',
  'remote-user' => 'boston.test',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['test.livedev'] = array(
  'parent' => '@boston.test',
  'root' => '/mnt/gfs/boston.test/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site boston, environment uat
$aliases['uat'] = array(
  'root' => '/var/www/html/boston.uat/docroot',
  'ac-site' => 'boston',
  'ac-env' => 'uat',
  'ac-realm' => 'prod',
  'uri' => 'bostonuat.prod.acquia-sites.com',
  'remote-host' => 'staging-15139.prod.hosting.acquia.com',
  'remote-user' => 'boston.uat',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['uat.livedev'] = array(
  'parent' => '@boston.uat',
  'root' => '/mnt/gfs/boston.uat/livedev/docroot',
);
