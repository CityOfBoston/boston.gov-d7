#!/bin/bash

set -e

# Every time we start up we need to make sure that we can write to this
# directory.
chown -R www-data /boston.gov/docroot/sites/default/files

# We need to set the permissions here because on AWS this is a bind mount.
chmod 1777 /tmp

# Delegate to the default entrypoint.
docker-php-entrypoint "$@"
