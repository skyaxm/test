#!/bin/bash

func()
{
    echo $1
    for((i=1; i<50; i++))
    do
        let sum+=i
    done
    echo ${sum}
    if (("$1" == 1))
    then
        echo "confirm the $1"
    fi
    return $1 
}
func 1 2 3
while (( "$?" != 0 ))
do
    let cnt=cnt+1
    if (( $cnt == 3 ));then
        echo "reach the max count $cnt"
        break
    fi
    func 1
done
