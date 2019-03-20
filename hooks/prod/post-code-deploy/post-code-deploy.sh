#!/bin/bash
#
# Cloud Hook: post-code-deploy
#
# The post-code-deploy hook is run whenever you use the Workflow page to
# deploy new code to an environment, either via drag-drop or by selecting
# an existing branch or tag from the Code drop-down list. See
# ../README.md for details.
#
# Usage: post-code-deploy site target-env source-branch deployed-tag repo-url
#                         repo-type

#
# @see readme.md for City of Boston specific notes.
#


site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$target_env" = 'prod' ]; then
    # Add utility functions
    . "/var/www/html/${site}.${target_env}/hooks/common/cob_utilities.sh"

    echo -e "\n$site.$target_env: A successful commit to $source_branch branch has caused a code update on $target_env environment of $site environment."

    echo "This hook will now synchronise the $target_env database with updated code."

    # Use acapi command (rather than drush db-dump) because this will cause the backup
    # to be shown the the acquia UI.
    echo "- Backing up the current $site database on ${target_env}."
    TASK=$(drush @${site}.${target_env} ac-database-instance-backup ${site} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1 --format=json)
    RES=$(monitor_task "${TASK}" "@${site}.${target_env}" 500)
    echo "Result: ${RES}"
    if [ "${RES}" != "done" ]; then
        echo -e "\nERROR BACKING UP DATABASE IN DEV ENVIRONMENT.\n"
        exit 1
    fi

    # Sync the copied database with the recently updated/deployed code.
    echo "- Update database ($site) on $target_env with configuration from updated code in $source_branch."
    sync_db @${site}.${target_env}
fi
