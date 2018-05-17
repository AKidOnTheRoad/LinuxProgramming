#!/bin/bash 

#############################################################
  # File name:      judge.sh
  #Author:         xiaofeifeng
  #Mail:           xiaofeifeng@nettech-global.com
  #Created Time:   2018-05-17 13:35:39 weeks:20
#############################################################

for file in `ls` 
do
	if [ -x "$file" ] && ! [ -d "$file" ] \
		&& [ ${file%%*.} != "sh" ]; then
		rm -rf "$file"
	fi
done
