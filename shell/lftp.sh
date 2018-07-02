#!/bin/bash
# File name:      lftp.sh
#Author:         xiaofeifeng
#Mail:           xiaofeifeng@nettech-global.com
#Created Time:   2018-06-29 09:50:47 weeks:26

if [ $# -lt 3 ]; then
	echo "lose argument:user passwd ftplink"
	exit
fi
rm -rf u-boot.bin
user=$1
passwd=$2
link=$3
lftp << EOF
open ftp://${user}:${passwd}@${link}
get u-boot.bin
EOF
