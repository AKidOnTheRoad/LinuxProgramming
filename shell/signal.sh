#!/bin/bash
# File name:      signal.sh
# Author:         xiaofeifeng
# Mail:           jy_fengxiaofei@163.com
# Created Time:   2018-06-30 15:22:40 weeks:26

function handler()
{
	echo received signal:SIGINT
}

trap 'handler' SIGINT

echo PID is $$
while [[ 1 ]];
do
	sleep 1
done
