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

if [ "$target_env" = 'uat' ] || [ "$target_env" = 'ci' ]; then

    # THIS HOOK USED FOR UAT AND CI ENVIRONMENTS ONLY.

    echo "$site.$target_env: A successful commit to $source_branch branch has caused a code update on $target_env environment of $site environment."
    echo "This hook will now synchronise the $target_env database with updated code."

    if [ ${site} = "boston" ]; then

        if [ "$target_env" = 'ci' ]; then
            # Place CI-specific commands/configurations here
            echo "== CI Environment Specific =="
#            echo "Copy database from stage (aka test) to $target_env."
#            drush @${site}.test ac-database-copy ${site} ${target_env} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1
        elif [ "$target_env" = 'uat' ]; then
            # Place UAT-specific commands/configurations here
            echo "== UAT Environment Specific =="
#             echo "Copy database from stage (aka test) to $target_env."
#             drush @${site}.test ac-database-copy ${site} ${target_env} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1
            # redirect to a different patterns CDN.
#             drush @${site}.${target_env} vset "asset_url" "https://cob-patterns-staging.herokuapp.com/"
        fi
        echo "== End Environment Specific commands =="

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

        echo "=== Code update completed ==="

    elif [ ${site} = "thehub" ]; then

        echo "Copy database from stage (aka test) to $target_env."
#        drush @${site}.test ac-database-copy ${site} ${target_env}

        if [ "$target_env" = 'ci' ]; then
            # Place CI-specific commands/configurations here
            echo "CI Environment."
        elif [ "$target_env" = 'uat' ]; then
            # Place UAT-specific commands/configurations here
            echo "UAT Environment."
        fi

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

        echo "=== Code update completed ==="
    fi
fi
