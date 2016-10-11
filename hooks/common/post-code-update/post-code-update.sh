#!/bin/sh
#
# Cloud Hook: post-code-update
#
# The post-code-update hook runs in response to code commits.
# When you push commits to a Git branch, the post-code-update hooks runs for
# each environment that is currently running that branch.. See
# ../README.md for details.
#
# Usage: post-code-update site target-env source-branch deployed-tag repo-url
#                         repo-type

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$target_env" = 'dev' ]; then
    echo "$site.$target_env: The $source_branch branch has been updated on $target_env. Clearing the cache."
else
    echo "$site.$target_env: The $source_branch branch has been updated on $target_env."
fi

# Perform database updates on dev and stage after a code deploy.
if [ "$target_env" != 'prod' ] &&  [ "$target_env" != 'test' ]; then
  drush sql-sync @$site.test @$site.$target_env --create-db --structure-tables-key=lightweight -y
  drush @$site.$target_env cc all
  drush @$site.$target_env cc drush
  drush @$site.$target_env fra -y
  drush @$site.$target_env updb -y
  drush @$site.$target_env fra -y
  drush @$site.$target_env cc all
  drush @$site.$target_env acquia-reset-permissions -y
  drush @$site.$target_env cron
fi
