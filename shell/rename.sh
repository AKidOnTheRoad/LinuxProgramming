#!/bin/bash
# File name:      rename.sh
# Author:         xiaofeifeng
# Mail:           jy_fengxiaofei@163.com
# Created Time:   2018-06-24 14:05:48 weeks:25

for name in `ls` 
do
	if [ ${name##*.} == "txt" -a -f ${name} ]; then
		cp  "$name"  ${name%.*}.img
	fi
done
