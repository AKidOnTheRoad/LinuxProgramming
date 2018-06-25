#!/bin/bash
# File name:      list_maxfile.sh
#Author:         xiaofeifeng
#Mail:           xiaofeifeng@nettech-global.com
#Created Time:   2018-06-25 19:29:21 weeks:26

function list_maxfile() 
{
	find . \( -name ".git*" -prune \) -o \( -type f -exec stat -c "%s %n" {} \; \) | sort -rn | head -10 
}

list_maxfile
