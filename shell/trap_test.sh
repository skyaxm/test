#!/bin/bash

trap 'rm -rf /tmp/my_tmp_file_$$' INT
echo create file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

echo "pleanse CTRL-C to interrupt ...."
while [ -f /tmp/my_tmp_file_$$ ]; do
	echo File exists
	sleep 1
done
echo the file is not exist

trap INT
echo create file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

echo "pleanse CTRL-C to interrupt ...."
while [ -f /tmp/my_tmp_file_$$ ]; do
	echo File exists
	sleep 1
done
echo the file is not exist
exit 0
