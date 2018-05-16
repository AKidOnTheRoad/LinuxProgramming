#!/bin/bash 
model_array=(
	"1:TRENDNET" "2:DLINK" "3:ELECOM"
	)

array_match=("MFLAG = yes" "MFLAG = no")


for arr in ${model_array[*]}
do
	echo ${arr}
done

while read -p "Please choose which model you want:" mode
do
	if [ $mode == "exit" -o $mode == "quit" ]
	then
		exit 0
	fi
		case $mode in
		1)
			echo ${array_match[$mode - 1]} > ./env.mk
			  exec make clean all ;;
		2)
			;;
		*)
			echo Invaild command!!!;;
	esac

done
