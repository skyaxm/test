#!/bin/bash

#CUR_DIR=$(cd "$(dirname "$0")"; pwd)
CUR_DIR=$(cd `dirname "$0"`; pwd)
echo $CUR_DIR
if [[ $# == 1  ]]; then
    echo $@
else
    echo "error arg"
fi

echo "$1/media/"
