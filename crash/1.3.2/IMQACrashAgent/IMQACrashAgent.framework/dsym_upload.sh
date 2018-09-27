#!/bin/sh
#
# Copyright (C) 2018 Onycom Inc. All rights reserved.
#

echoMessageAndExitWithCode() {
    echo "${1}"
    exit ${2}
}

rawurlencode() {
    local string="${1}"
    local strlen=${#string}
    local encoded=""

    for (( pos=0 ; pos<strlen ; pos++ )); do
    c=${string:$pos:1}
    case "$c" in
    [-_.~a-zA-Z0-9] ) o="${c}" ;;
    * )               printf -v o '%%%02x' "'$c"
    esac
    encoded+="${o}"
    done
    echo "${encoded}"
}

uploadDsym() {

    local dsym_path="${1}"

    NOW=$(date +"%T")
    echo "Time ${NOW}. Started uploading dSYM to IMQA Processor. URL: ${DSYM_UPLOAD_URL}..."

    find "${dsym_path}/Contents/Resources/DWARF" -type f -name \* -print |
    while read dsym_file; do
    HTTP_STATUS=$(curl -H 'content-type: multipart/form-data'
                       -F "file_dir=@${dsym_file}"
                       -F "pack_name=${PRODUCT_NAME}"
                       -F "app_version=${BUNDLE_SHORT_VERSION}"
                       -F "build_version=${BUNDLE_VERSION}"
                       "https://ote-mpm.imqa.io/api/upload/dsym"
    )
    done

    CURL_STATUS=$?
    NOW=$(date +"%T")

    echo "Time ${NOW}. Upload attempt completed. curl return code: ${CURL_STATUS}"
}

checkUploadStatus() {

    if [ $HTTP_STATUS -ne 200 -o $CURL_STATUS -ne 0 ]; then
    if [ $ADRUM_TREAT_UPLOAD_FAILURES_AS_ERRORS -eq 1 ]; then
    MESSAGE=$(printf "error: dSYM archive upload failed\nTo ignore this condition and build succesfully")
    echoMessageAndExitWithCode "${MESSAGE}" 1
    fi
    echo "warning: dSYM archive upload failed"
    fi
    echo "dSYM uploaded successfully to IMQA Processor"
}

echo "Uploading dSYM to IMQA Processor"
echo ""

BUNDLE_VERSION=$(/usr/libexec/PlistBuddy -c 'Print CFBundleVersion' ${INFOPLIST_FILE})
BUNDLE_SHORT_VERSION=$(/usr/libexec/PlistBuddy -c 'Print CFBundleShortVersionString' ${INFOPLIST_FILE})

echo "Product Name: ${PRODUCT_NAME}"
echo "Product Version: ${BUNDLE_SHORT_VERSION}"
echo "Product Build: ${BUNDLE_VERSION}"

APP_DSYM=${DWARF_DSYM_FOLDER_PATH}/${DWARF_DSYM_FILE_NAME}

# Check if App dSym file exists
echo "App dSYM file location: ${APP_DSYM}"
if [ ! -d "$APP_DSYM" ]; then
echoMessageAndExitWithCode "error: App dSYM file not found at: ${APP_DSYM}" 1
fi

DSYM_UPLOAD_URL="https://ote-mpm.imqa.io/api/upload/dsym"

find ${DWARF_DSYM_FOLDER_PATH} -type d -name \*.dSYM -print |
while read dsym; do
    uploadDsym "${dsym}"
    checkUploadStatus
done
