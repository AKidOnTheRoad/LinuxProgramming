
C_FLAGS = -c 
CC = gcc

.PHONY:all clean

all:t_getopt

t_getopt:t_getopt.o
	$(CC) -o $@ $<

clean:
	@rm -rf t_getopt.o t_getopt
