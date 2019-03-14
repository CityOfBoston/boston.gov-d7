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

# Run the same code as post-code-update
/mnt/users/${site}/${target_env}.shell /var/www/html/boston.${target_env}/hooks/${target_env}/post-code-update/post-code-update.sh ${0} < /dev/null
