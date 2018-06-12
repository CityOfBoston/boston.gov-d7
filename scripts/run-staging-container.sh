#!/bin/bash

# Command for the drupal container when we deploy to the staging cluster on AWS.
# Similar to the init-docker-container.sh script run locally.
#
# Initializes the container and its database with the latest from Acquia staging
# by running the build:local task.

set -e

if [ -z "$AWS_S3_CONFIG_URL" ]; then
  echo >&2 'error: missing AWS_S3_CONFIG_URL environment variable'
else
  # Pulls things down from our staging config S3 bucket.
  #
  # We include --no-follow-symlinks because there is a broken symlink in the
  # docroot (simplesaml) that causes aws to exit with status code 2, which
  # causes the script to exit. Since we don’t need symlinks for the sync, this
  # is fine.
  aws s3 sync --no-follow-symlinks $AWS_S3_CONFIG_URL .

  # We need this info to run drush commands in the Acquia cloud (for example, to
  # pull down the staging DB). This puts it in places where the tools will find
  # it.
  tar -C /root -xf ./acquia-cloud.drush-aliases.tar.gz
  mv ./.ssh /root
  chmod 400 /root/.ssh/id_rsa
fi

# Sets up the database by initializing from the latest copy of the staging DB
# from Acquia, then runs local unapplied install hooks.
./task.sh build:local

# Necessary so that Apache can write proxied assets to the filesystem.
chown -R www-data /boston.gov/docroot/sites/default/files 

# Since we’re overriding the default Apache/PHP container’s command, we run this
# ourselves.
apache2-foreground
