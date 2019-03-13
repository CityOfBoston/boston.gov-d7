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

# ======== City of Boston Notes ===============================
# Mar 2019: COB deploy workflow starts with a commit/merge to the develop branch of the CoB "boston.gov-d7" github repo
#           (usually in the github UI). Travis then initiates an update to the develop-build branch of the Acquia-hosted
#           git repo.  Beyond merging/commiting in github, no other actions are required.
# Mar 2019: The "City of Boston" and "Hub" application develop environment is linked to the "develop-build" branch in
#           the repo managed by Acquia.
#
# Mar 2019: Each Applications develop environment is always the first step in the deploy chain.  No manual action is
#           required, this hook does all the necessary tasks to update the develop environment in each Application.
#
# Mar 2019: When ready to move through the deploy workflow, the github develop branch is merged to the master branch.
#           Travis then initiates an update to the master-build branch of the Acquia-hosted git repo.  Beyond
#           merging/commiting in github, no other actions are required.
# Mar 2019: Each Applications stage environment is linked to the "master-build" branch in the repo managed by Acquia.

# Mar 2019: When ready to deploy to live, code is simply dragged from the develop to the prod environment to update the
#           live boston.gov website.
# Mar 2019: These Aquia hooks manage the backup and synchronization of databases, so the only manual deploy actions
#           required are to drag code around in the Acquia Cloud UI.

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$target_env" = 'prod' ]; then
    # Add utility functions
    . "/var/www/html/boston.dev/hooks/common/cob_utilities.sh"

    echo "\n$site.$target_env: A successful commit to $source_branch branch has caused a code update on $target_env environment of $site environment."

    echo "This hook will now synchronise the $target_env database with updated code."

    # Use acapi command (rather than drush db-dump) because this will cause the backup
    # to be shown the the acquia UI.
    echo "- Backing up the current $site database on ${target_env}."
    TASK=$(drush @${site}.${target_env} ac-database-instance-backup ${site} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1 --format=json)
    RES=$(monitor_task "${TASK}" "@${site}.${target_env}" 300)
    echo "Result: ${RES}"
    if [ "${RES}" != "done" ]; then
        echo "\nERROR BACKING UP DATABASE IN DEV ENVIRONMENT.\n"
        exit 1
    fi

    # Sync the copied database with the recently updated/deployed code.
    echo "- Update database ($site) on $target_env with configuration from updated code in $source_branch."
    sync_db @${site}.${target_env}
fi
