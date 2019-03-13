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

# Run the same code as post-code-update
/mnt/users/boston/dev.shell /var/www/html/boston.dev/hooks/test/post-code-update/post-code-update.sh ${0} < /dev/null
