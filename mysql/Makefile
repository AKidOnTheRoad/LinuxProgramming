
.PHONY:all clean

CC = gcc
CFLAGS = -I/usr/include/mysql  -L/usr/lib/mysql
all:mysql

mysql:c_invocate_mysql.o
	$(CC) -o $@ $< -lmysqlclient
	
#mysql.o:mysql.c
#	$(CC) $(C_FLAGS) -o $@ $< 

clean:
	@rm -rf mysql c_invocate_mysql.o
