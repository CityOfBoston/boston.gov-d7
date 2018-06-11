#!/bin/bash

set -e
set -x

# We want to symlink specific directories from the host into
# the Apache docroot. This speeds things up by keeping the
# vendor files just within the container. Pulling files across
# the bind volume is slow in comparison.
paths=(
  docroot/profiles
  docroot/sites/default
  docroot/sites/hub
  docroot/sites/all/modules/custom
  docroot/sites/all/modules/features
  docroot/sites/all/settings
  docroot/sites/all/themes/custom
)

for p in "${paths[@]}"
do
  rm -rf "./${p}"
  ln -s "/host-repo/${p}" "./${p}"
done

# Uncomment next line to copy files in mounted ssh folder from host into container to ensure root:root permissions.
# cp -rfu ~/host-ssh/ ~/.ssh/

if [ "$1" = "hub" ]
then
  ./hub-task.sh -Dproject.build_db_from=initialize build:local
else
  ./task.sh -Dproject.build_db_from=initialize build:local
  chown www-data /boston.gov/docroot/sites/default/files 
fi