#!/usr/bin/env bash

# This script simply calls task.sh with the additional -propertyfile option.
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
${DIR}/task.sh -propertyfile ${DIR}/build/custom/phing/hub.yml -propertyfileoverride "$@"
