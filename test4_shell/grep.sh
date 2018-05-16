#!/bin/bash 

function gg()
{
	if [ ! -f "$2" ];then
		echo "$2 is not existed."
	fi

	if [ grep -i "$1" "$2" ];then
		return 0
	fi
	return 1
}

gg "$1" "$2"
if [ $? == 0 ];then
	echo "$1"
fi



