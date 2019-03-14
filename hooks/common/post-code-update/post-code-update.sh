#!/bin/bash
#
# Cloud Hook: post-code-update
#
# The post-code-update hook runs in response to code commits.
# When you push commits to a Git branch, the post-code-update hooks runs for
# each environment that is currently running that branch.. See
# ../README.md for details.
#
# @see readme.md for City of Boston specific notes.
#
# Usage: post-code-update site target-env source-branch deployed-tag repo-url
#                         repo-type


site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

# Add utility functions
. "/var/www/html/${site}.${target_env}/hooks/common/cob_utilities.sh"

if [ "$target_env" = 'uat' ] || [ "$target_env" = 'ci' ]; then

    # THIS HOOK USED FOR UAT AND CI ENVIRONMENTS ONLY.

    echo "$site.$target_env: A successful commit to $source_branch branch has caused a code update on $target_env environment of $site environment."
    echo "This hook will now synchronise the $target_env database with updated code."

    if [ ${site} = "boston" ]; then

        echo "- Backing up the current $site database on ${target_env}."
        TASK=$(drush @${site}.${target_env} ac-database-instance-backup ${site} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1 --format=json)
        RES=$(monitor_task "${TASK}" "@${site}.${target_env}" 500)

        sync_db @${site}.${target_env}

        if [ "$target_env" = 'ci' ]; then
            # Place CI-specific commands/configurations here
            echo "== CI Environment Specific =="
#            echo "Copy database from stage (aka test) to $target_env."
#            drush @${site}.test ac-database-copy ${site} ${target_env} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1
        elif [ "$target_env" = 'uat' ]; then
            # Place UAT-specific commands/configurations here
            echo "== UAT Environment Specific =="
            if [ "${deployed_tag}" = "bibblio-build" ]; then
                # redirect to a different patterns CDN.
                drush @${site}.${target_env} vset "asset_url" "https://cob-patterns-staging-pr-436.herokuapp.com/"
            fi
        fi
        echo "== End Environment Specific commands =="

        echo "=== Code update completed ==="

    elif [ ${site} = "thehub" ]; then

        echo "- Backing up the current $site database on ${target_env}."
        TASK=$(drush @${site}.${target_env} ac-database-instance-backup ${site} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1 --format=json)
        RES=$(monitor_task "${TASK}" "@${site}.${target_env}" 500)

        sync_db @${site}.${target_env}

        if [ "$target_env" = 'ci' ]; then
            echo "== CI Environment Specific =="
            # Place CI-specific commands/configurations here
        elif [ "$target_env" = 'uat' ]; then
            echo "== UAT Environment Specific =="
            # Place UAT-specific commands/configurations here
        fi
        echo "== End Environment Specific commands =="

        echo "=== Code update completed ==="
    fi
fi
