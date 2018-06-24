#!/bin/bash
# File name:      generate_cksum.sh
# Author:         xiaofeifeng
# Mail:           jy_fengxiaofei@163.com
# Created Time:   2018-06-24 14:30:02 weeks:25

PIDARR=()
for file in `ls`
do
	if [ -f $file -a ${file##*.} == "txt" ]; then
	md5sum $file &
	PIDARR+=("$!")
    fi
done
wait ${PIDARR[@]}
