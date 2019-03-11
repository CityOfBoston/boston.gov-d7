#!/bin/sh

parse_json() {
    SCRIPT="\$json='${1}'; \$a=json_decode(\$json); print \$a->${2};"
    echo $(php -r "${SCRIPT}")
}
monitor_task() {
    TASKID=$(parse_json "${1}" "id")
    LOOP_INCREMENT=15
    TIMEOUT=180
    if [ "${3}" != "" ]; then TIMEOUT=${3}; fi
    sleep $(( ${LOOP_INCREMENT} * 2 ))
    LOOP_COUNT=$(( ${LOOP_INCREMENT} * 2 ))

    while true; do
      # Wait for a new backup file to be created.
      STATUS=$(drush ${2} ac-task-info ${TASKID} --email=${ac_api_email} --key=${ac_api_key} --endpoint=https://cloudapi.acquia.com/v1 --format=json)
      STATE=$(parse_json "${STATUS}" "state")

      if [ "${STATE}" = "done" ]; then break; fi
      if [ "${STATE}" = "error" ]; then
        STATE=$(parse_json "${STATUS}" "result")
        break;
      fi
      if (( ${LOOP_COUNT} > ${TIMEOUT} )); then
        STATE="timeout"
        break
      fi
      sleep ${LOOP_INCREMENT}
      LOOP_COUNT=$(( ${LOOP_COUNT} + ${LOOP_INCREMENT} ))
    done
    echo "${STATE}"
}
