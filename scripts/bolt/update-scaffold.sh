#!/bin/bash -e

GIT_ROOT=$(git rev-parse --show-toplevel)
BOLT_BRANCH=7.x

# Upstream directories to pull. These will be prefixed with "template/".
BOLT_DIRS=( "scripts/git-hooks" "scripts/make" )

# Move into repository root.
cd $GIT_ROOT

echo "Copying down upstream changes to the Bolt template."

# Iteratively pull down upstream directories.
for i in "${BOLT_DIRS[@]}"
  do
    svn export https://github.com/acquia/bolt/branches/$BOLT_BRANCH/template/$i $i --force
done

# Restore execute permissions.
chmod 755 task.sh

echo "Changes have been pulled down. Please review and commit desired changes."
