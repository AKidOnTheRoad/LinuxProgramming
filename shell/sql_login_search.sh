#!/bin/bash
# File name:      sql_login_search.sh
# Author:         xiaofeifeng
# Mail:           jy_fengxiaofei@163.com
# Created Time:   2018-07-01 14:45:31 weeks:26

if [ $# -lt 2 ]; then
	echo lose argument
fi

user=$1
passwd=$2

mysql -u $user -p$passwd << EOF 2> /dev/null 
create database feisql;
EOF

[ $? -eq 0 ] && echo Created successfully || echo The database is existed.


mysql -u $user -p$passwd << EOF 2> /dev/null 
use feisql;
create table debug(id int not null auto_increment primary key,name char(20),pwd
char(20));
select * from debug;
insert into debug value(1,'xiao','asd');
select * from debug;
EOF
