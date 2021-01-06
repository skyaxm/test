#!/bin/bash

arg=$1
until [ "$arg" = "enter" ]
do
	read arg
	echo "not input"
done 
