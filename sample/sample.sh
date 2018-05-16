#!/bin/bash 
while read -p "input the character:" var
do
	echo  ${var}
	if [ "${var}" == "quit" -o "${var}" == "q" ]; then
		exit 0
	fi
done
