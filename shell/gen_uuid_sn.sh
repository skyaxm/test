#!/bin/bash

uuid_path=/media/uuid.txt
sn_path=/media/sn.txt
if [ ! -f ${uuid_path} ]; then
    echo `cat /proc/sys/kernel/random/uuid` > ${uuid_path}
fi
if [ ! -f ${sn_path} ]; then
    echo "4567891234567890" > ${sn_path}
fi
cp ${uuid_path} /tmp/
cp ${sn_path} /tmp/
