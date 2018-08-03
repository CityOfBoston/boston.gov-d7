#!/usr/bin/bash

# Cloud Hook: drush_vset_asset_url
#
# Run drush vset in the target environment.

# Map the script inputs to convenient names.
site=$1
target_env=$2
drush_alias=$site'.'$target_env

# Causes the main public.css to be served from the patterns staging environment.
drush vset @$drush_alias asset_url https://cob-patterns-staging.herokuapp.com/
