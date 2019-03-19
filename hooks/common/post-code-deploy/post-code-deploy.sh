#!/bin/bash
#
# Cloud Hook: post-code-deploy
#
# The post-code-deploy hook is run whenever you use the Workflow page to
# deploy new code to an environment, either via drag-drop or by selecting
# an existing branch or tag from the Code drop-down list. See
# ../README.md for details.
#
# @see readme.md for City of Boston specific notes.
#
# Usage: post-code-deploy site target-env source-branch deployed-tag repo-url
#                         repo-type

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$source_branch" != "$deployed_tag" ]; then
    echo "$site.$target_env: Deployed branch $source_branch as $deployed_tag."
else
    echo "$site.$target_env: Deployed $deployed_tag."
fi

# Run the same code as post-code-update
if [ "$target_env" = 'uat' ] || [ "$target_env" = 'ci' ]; then
    /mnt/users/${site}/${target_env}.shell /var/www/html/boston.${target_env}/hooks/${target_env}/post-code-update/post-code-update.sh ${0} < /dev/null
fi
