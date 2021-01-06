#!/bin/bash

fun_test()
{
	echo $@
	return 3
}

ret=$(fun_test 1 2 3)
echo "res: "${ret}
echo $?
