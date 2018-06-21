#!/bin/bash 
n0=$1
n1=$2
echo ${n0}
echo ${n1}
let result=n0+n1
echo $result
result=$[n0/n1]
echo $result
