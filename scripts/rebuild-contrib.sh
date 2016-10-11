#! /bin/bash -e

# Rebuilds the patches applied to the repo. Won't build core.

GIT_ROOT=$(git rev-parse --show-toplevel)
cd $GIT_ROOT/sites/all

echo "Building contrib projects..."
drush make $GIT_ROOT/scripts/project.make.yml -y --no-core --no-gitinfofile --contrib-destination=. --concurrency=8
echo "Complete"
