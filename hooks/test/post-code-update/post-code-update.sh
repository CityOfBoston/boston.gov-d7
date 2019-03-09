#!/bin/sh
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

# ======== City of Boston Notes ===============================
# Jan 2019: COB deploy workflow starts with a commit/merge to the master branch of the CoB "boston.gov-d7" github repo
#           (usually in the github UI). Travis then initiates an update to the master-build branch of the Acquia-hosted
#           git repo.  Beyond merging/commiting in github, no other actions are required.
# Jan 2019: Each Applications develop environment is linked to the "master-build" branch in the repo managed by Acquia.
# Jan 2019: Each Applications develop environment is always the first step in the deploy chain.  No manual action is
#           required, this hook does all the necessary tasks to update the develop environment in each Application.
# Jan 2019: When ready to move through the deploy workflow, code is simply dragged from the develop to the stage
#           environment where testing ocurs, and then code is dragged from the stage environment to prod to deploy all
#           updates to the live boston.gov website.
# Jan 2019: These Aquia hooks manage the backup and synchronization of databases, so the only manual deploy actions
#           required are to drag code around in the Acquia Cloud UI.

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$target_env" = 'test' ]; then
    echo "$site.$target_env: A code-copy (deploy) to $source_branch branch has caused a code update on $target_env environment of $site environment."
    echo "This hook will now synchronise the $target_env database with updated code."

    if [ ${site} = "boston" ]; then

        echo "Backing up the current $site database on ${target_env}."
        drush @${site}.${target_env} ac-database-instance-backup ${site} --email=${ac_api_email} --key={ac_api_key}

        echo "Copy database from production to $target_env."
        # Use acapi command (rather than sql-sync) because this will cause the DB copy hooks to run.
        drush @${site}.prod ac-database-copy ${site} ${target_env} --email=${ac_api_email} --key={ac_api_key}

        echo "Update database ($site) on $target_env with configuration from updated code in $source_branch."
        drush @${site}.${target_env} en stage_file_proxy -y
        drush @${site}.${target_env} vset "stage_file_proxy_origin" "https://www.boston.gov"
        drush @${site}.${target_env} cc drush
        drush @${site}.${target_env} fra -y
        drush @${site}.${target_env} updb -y
        drush @${site}.${target_env} fra -y

        echo "Refresh all permissions and force run a cron task now."
        drush @${site}.${target_env} acquia-reset-permissions -y
        drush @${site}.${target_env} cron

        echo "=== Code-copy (deploy) update completed ==="

    elif [ ${site} = "thehub" ]; then

        echo "Backing up the current $site database on ${target_env}."
        drush @${site}.${target_env} ac-database-instance-backup ${site} --email=${ac_api_email} --key={ac_api_key}

        echo "Copy database from producction to $target_env."
        # Use acapi command (rather than sql-sync) because this will cause the DB copy hooks to run.
        drush @${site}.prod ac-database-copy ${site} ${target_env} --email=${ac_api_email} --key={ac_api_key}

        echo "Update database ($site) on $target_env with configuration from updated code in $source_branch."
        drush @${site}.${target_env} en stage_file_proxy -y
        drush @${site}.${target_env} vset "stage_file_proxy_origin" "https://www.boston.gov"
        drush @${site}.${target_env} cc drush
        drush @${site}.${target_env} fra -y
        drush @${site}.${target_env} updb -y
        drush @${site}.${target_env} fra -y

        echo "Refresh all permissions and force run a cron task now."
        drush @${site}.${target_env} acquia-reset-permissions -y
        drush @${site}.${target_env} cron

        echo "=== Code-copy (deploy) update completed ==="
    fi
fi
