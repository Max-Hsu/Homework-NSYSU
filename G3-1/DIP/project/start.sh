#! /bin/bash
if [ -d "$1" ]
then
    todo=$(ls $1| sed "s/\(.*\)/$1\/\1/" |grep -e".*png$" -e ".*jpg$" -e ".*tif$")
    shift
    python3 do.py $todo $@
else
    todo=$(ls | grep -e".*png$" -e ".*jpg$" -e ".*tif$")
    python3 do.py $todo $@
fi