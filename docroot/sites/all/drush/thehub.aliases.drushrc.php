<?php
// DO NOT MODIFY THIS FILE.
// This file was created by the drush acquia-update command. Changes will be
// lost the next time drush acquia-update runs.

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site thehub, environment ci
$aliases['ci'] = array(
  'root' => '/var/www/html/thehub.ci/docroot',
  'ac-site' => 'thehub',
  'ac-env' => 'ci',
  'ac-realm' => 'prod',
  'uri' => 'thehubci.prod.acquia-sites.com',
  'remote-host' => 'staging-19375.prod.hosting.acquia.com',
  'remote-user' => 'thehub.ci',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['ci.livedev'] = array(
  'parent' => '@thehub.ci',
  'root' => '/mnt/gfs/thehub.ci/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site thehub, environment dev
$aliases['dev'] = array(
  'root' => '/var/www/html/thehub.dev/docroot',
  'ac-site' => 'thehub',
  'ac-env' => 'dev',
  'ac-realm' => 'prod',
  'uri' => 'thehubdev.prod.acquia-sites.com',
  'remote-host' => 'staging-19375.prod.hosting.acquia.com',
  'remote-user' => 'thehub.dev',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['dev.livedev'] = array(
  'parent' => '@thehub.dev',
  'root' => '/mnt/gfs/thehub.dev/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site thehub, environment prod
$aliases['prod'] = array(
  'root' => '/var/www/html/thehub.prod/docroot',
  'ac-site' => 'thehub',
  'ac-env' => 'prod',
  'ac-realm' => 'prod',
  'uri' => 'thehub.prod.acquia-sites.com',
  'remote-host' => 'web-19248.prod.hosting.acquia.com',
  'remote-user' => 'thehub.prod',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['prod.livedev'] = array(
  'parent' => '@thehub.prod',
  'root' => '/mnt/gfs/thehub.prod/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site thehub, environment ra
$aliases['ra'] = array(
  'root' => '/var/www/html/thehub.ra/docroot',
  'ac-site' => 'thehub',
  'ac-env' => 'ra',
  'ac-realm' => 'prod',
  'uri' => 'thehubra.prod.acquia-sites.com',
  'remote-host' => 'staging-14794.prod.hosting.acquia.com',
  'remote-user' => 'thehub.ra',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['ra.livedev'] = array(
  'parent' => '@thehub.ra',
  'root' => '/mnt/gfs/thehub.ra/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site thehub, environment test
$aliases['test'] = array(
  'root' => '/var/www/html/thehub.test/docroot',
  'ac-site' => 'thehub',
  'ac-env' => 'test',
  'ac-realm' => 'prod',
  'uri' => 'thehubstg.prod.acquia-sites.com',
  'remote-host' => 'staging-19375.prod.hosting.acquia.com',
  'remote-user' => 'thehub.test',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['test.livedev'] = array(
  'parent' => '@thehub.test',
  'root' => '/mnt/gfs/thehub.test/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site thehub, environment uat
$aliases['uat'] = array(
  'root' => '/var/www/html/thehub.uat/docroot',
  'ac-site' => 'thehub',
  'ac-env' => 'uat',
  'ac-realm' => 'prod',
  'uri' => 'thehubuat.prod.acquia-sites.com',
  'remote-host' => 'staging-19375.prod.hosting.acquia.com',
  'remote-user' => 'thehub.uat',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['uat.livedev'] = array(
  'parent' => '@thehub.uat',
  'root' => '/mnt/gfs/thehub.uat/livedev/docroot',
);
