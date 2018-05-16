#!/bin/bash 
if [ -f $PWD/abc -o -e $PWD/abc ]
then
	read -p "Do you want to delete (yes/no): " mode
	case ${mode} in
		yes)
			rm -rf $PWD/abc
			;;
		no)
			;;
		*)
			echo "Invaild Command!!!"
			;;
	esac
else
	mkdir $PWD/abc
fi
