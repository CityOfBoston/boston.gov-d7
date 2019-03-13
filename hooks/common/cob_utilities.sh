#!/bin/bash

parse_json() {
    JSON="$(echo ${1} | sed "s/{\(.*\), \"logs.*}/\1/" |  sed "s/{\(.*\), \"tags.*}/\1/" )"
    SCRIPT="\$json='{ ${JSON} }'; \$a=json_decode(\$json); print \$a->${2};"
    out=$(php -r "${SCRIPT}")
    echo $out;
}
monitor_task() {
    TASKID=$(parse_json "${1}" "id")
    LOOP_INCREMENT=15
    TIMEOUT=180
    if [ ! -z "${3}" ]; then
        TIMEOUT=$3
    fi
    LOOP_COUNT=$(($LOOP_INCREMENT*2))
    sleep $LOOP_COUNT

    while true; do
      # Wait for a new backup file to be created.
      STATUS=$(drush ${2} ac-task-info ${TASKID} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1 --format=json)
      STATE=$(parse_json "${STATUS}" "state")

      if [ "${STATE}" = "done" ]; then break; fi
      if [ "${STATE}" = "error" ]; then
        STATE=$(parse_json "${STATUS}" "result")
        break;
      fi
      if [ "$LOOP_COUNT" -gt "$TIMEOUT" ]; then
        STATE="timeout"
        break
      fi
      sleep $LOOP_INCREMENT
      LOOP_COUNT=$(( $LOOP_COUNT+$LOOP_INCREMENT ))
    done
    echo "${STATE}"
}
sync_db() {
    ALIAS=${1}
    echo "- Update database ($site) on $target_env with configuration from updated code in $source_branch."
    drush ${ALIAS} cc drush
    drush ${ALIAS} fra -y
    drush ${ALIAS} updb -y
    drush ${ALIAS} fra -y

    echo "- Refresh all permissions and force run a cron task now."
    drush ${ALIAS} acquia-reset-permissions -y
    drush ${ALIAS} cron
}