#!/bin/bash -e

# This script will use drush make to download Drupal core and then rsync
# specific files to a target directory. This allows drush make to be used
# without completely destroying an existing docroot.

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
GIT_ROOT=$(git rev-parse --show-toplevel)
DRUSH=$GIT_ROOT/vendor/bin/drush
# See http://unix.stackexchange.com/questions/30091/fix-or-alternative-for-mktemp-in-os-x
# if operating beneath OSX 10.11.
DRUPAL_TEMP=$(mktemp -d)
rm -rf $DRUPAL_TEMP

$DRUSH make make.yml $DRUPAL_TEMP --quiet -y --projects=drupal --no-gitinfofile --concurrency=10
rsync -a --no-g --no-p --delete --exclude-from=$DIR/rsync-exclude.txt --include-from=$DIR/rsync-include.txt $DRUPAL_TEMP/ $GIT_ROOT/docroot
rsync -a --no-g --no-p --delete --ignore-existing --files-from=$DIR/rsync-include-if-does-not-exist.txt $DRUPAL_TEMP/ $GIT_ROOT/docroot

rm -rf $DRUPAL_TEMP
