#! /bin/bash -e

GIT_ROOT=$(git rev-parse --show-toplevel)
cd $GIT_ROOT

echo "Rebuilding docroot..."
rm -r docroot
drush make $GIT_ROOT/scripts/project.make.yml docroot -y --no-gitinfofile --concurrency=8
echo "Complete"
