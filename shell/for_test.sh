#!/bin/bash

for file in $(ls /root/*.sh);
do
	printf "%s\n" $file
done

for ((i=0;i<10;i++))
do
	echo $i
done
exit 0
