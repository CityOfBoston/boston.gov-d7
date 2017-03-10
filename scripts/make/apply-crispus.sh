#!/usr/bin/env bash

# What does this script do?
# This script will watch for a Travis build on a specific
# $source_branch on the canonical GitHub repository and apply
# environment specific settings prior to deployment

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
GIT_ROOT=$(git rev-parse --show-toplevel)
DOCROOT=$GIT_ROOT/docroot

# Fail on error
set -e

echo "--------------------------------"
echo "Cloning patterns"
git clone -b gh-pages --single-branch git@github.com:CityOfBoston/patterns.git ${DIR}/tmp/patterns
echo "Patterns cloned. Release the kraken!"
echo "--------------------------------"
rm -Rf ${DIR}/tmp/patterns/.git
mv ${DIR}/tmp/patterns $DOCROOT/crispus
echo "Applied Crispus"
echo "--------------------------------"
