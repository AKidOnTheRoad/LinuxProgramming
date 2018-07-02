#!/bin/bash
# File name:      diag_shell.sh
#Author:         xiaofeifeng
#Mail:           xiaofeifeng@nettech-global.com
#Created Time:   2018-07-02 19:36:52 weeks:27


if [ -e diag -a -f diag ]; then
	cat cmds - | ./diag
else
	echo lose the excuting file named diag.
fi
