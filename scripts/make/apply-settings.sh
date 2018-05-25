#!/usr/bin/env bash

# What does this script do?
# This script will watch for a Travis build on a specific
# $source_branch on the canonical GitHub repository and apply
# environment specific settings prior to deployment

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
GIT_ROOT=$(git rev-parse --show-toplevel)
DOCROOT=$GIT_ROOT/docroot

# Fail on error
set -e

echo "--------------------------------"
if [[ "${TRAVIS_BRANCH}" = "settings" ]]; then
  echo "Cloning settings (From settings-develop branch)"
  git clone -b settings-develop git@github.com:CityOfBoston/boston.settings.git ${DIR}/tmp/settings
  echo "Settings cloned from settings-develop. Release the kraken!"
else
  echo "Cloning settings"
  git clone git@github.com:CityOfBoston/boston.settings.git ${DIR}/tmp/settings
  echo "Settings cloned. Release the kraken!"
fi
echo "--------------------------------"
rm -Rf $DOCROOT/.htaccess
mv ${DIR}/tmp/settings/.htaccess $DOCROOT/.htaccess
echo "Applied HTACCESS"
echo "--------------------------------"
rm -Rf $DOCROOT/sites/default/settings/auth.settings.php
rm -Rf $DOCROOT/sites/default/settings/cache.settings.php
rm -Rf $DOCROOT/sites/default/settings/edit-domain.settings.php
rm -Rf $DOCROOT/sites/default/settings/saml.settings.php
mv ${DIR}/tmp/settings/boston.gov/*.settings.php $DOCROOT/sites/default/settings/
echo "Applied Boston.gov settings"
echo "--------------------------------"
rm -Rf $DOCROOT/sites/hub/settings/auth.settings.php
rm -Rf $DOCROOT/sites/hub/settings/cache.settings.php
rm -Rf $DOCROOT/sites/hub/settings/edit-domain.settings.php
rm -Rf $DOCROOT/sites/hub/settings/saml.settings.php
mv ${DIR}/tmp/settings/hub.boston.gov/*.settings.php $DOCROOT/sites/hub/settings/
echo "Applied settings to The Hub"
echo "--------------------------------"
rm -Rf $DOCROOT/simplesamlphp
mv ${DIR}/tmp/settings/simplesamlphp* $GIT_ROOT/simplesamlphp
echo "Applied saml settings"
echo "--------------------------------"
rm -Rf ${DIR}/tmp
echo "Removed temporary settings"
