
CC = gcc
C_FLAGS = -c -o

.PHONY:all clean

all:timed_read

timed_read:timed_read.o
	$(CC) -o $@ $<

clean:
	@rm -rf timed_read timed_read.o
