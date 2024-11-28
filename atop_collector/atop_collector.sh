#!/usr/bin/env bash

LOGGING_DIRECTORY=/tmp/atoplogs
LOGFILE_NAME=/tmp/atopcollector_$(date +%Y%m%dT%H%M%S).log
ATOP_SAMPLE_INTERVAL_SECONDS=5
ATOP_SAMPLE_COUNT=720
ATOP_LOG_RETENTION_COUNT=24

function log_message {
        echo "$(date +%Y/%m/%dT%H:%M:%S) | $@" | tee -a ${LOGFILE_NAME}
}

function check_root {
        if (( ${UID} != 0 )); then
                        return 1
        else
                        return 0
        fi
}


function start_logging {
        FILENAME=${LOGGING_DIRECTORY}/"atop_"$(date +%Y%m%dT%H%M%S)".log"
        log_message "starting atop collection in ${FILENAME}"
        sudo atop -w ${FILENAME} -L 512 ${ATOP_SAMPLE_INTERVAL_SECONDS} ${ATOP_SAMPLE_COUNT}
        log_message "stopping atop collection in ${FILENAME}"
}

function check_and_rotate_logs {
        ATOP_FILE_COUNT=$(ls -alt ${LOGGING_DIRECTORY}/atop_*.log | wc -l)
        if (( ${ATOP_FILE_COUNT} > ${ATOP_LOG_RETENTION_COUNT} )); then
                log_message "rotating atop logs since our file count is ${ATOP_FILE_COUNT}"
                FILE_COUNT_TO_BE_DELETED=$(( ${ATOP_FILE_COUNT} - ${ATOP_LOG_RETENTION_COUNT} ))
                FILES_TO_BE_DELETED=$(ls -at ${LOGGING_DIRECTORY}/atop_*.log | tail -${FILE_COUNT_TO_BE_DELETED})
                log_message "deleting ${FILES_TO_BE_DELETED}"
                if rm -f ${FILES_TO_BE_DELETED}; then
                        log_message "deletion successfull"
                else
                        log_message "error deleting log files $?"
                fi
        else
                log_message "no need for rotation of atop_* logs file count is ${ATOP_FILE_COUNT} < ${ATOP_LOG_RETENTION_COUNT}"
        fi
}

function main {
        if ! check_root; then
                log_message "need to be run root priviliges"
                exit -1
        fi
        [[ -d ${LOGGING_DIRECTORY} ]] || mkdir -p ${LOGGING_DIRECTORY}
        start_logging
        check_and_rotate_logs
}

main "$@"