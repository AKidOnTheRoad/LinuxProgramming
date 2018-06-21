#!/bin/bash 
ifs=$IFS
IFS=$'\n'

while read line
do
	if [ "$line" == ' ' ];then
		break
	fi
	echo "$line" >> "$1"
done
IFS=$ifs
