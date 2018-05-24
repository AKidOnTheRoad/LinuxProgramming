
CC = gcc
C_FLAGS = -c -I.

.PHONY:clean shmset shmget 

shmget:shmget.o
	$(CC) -o $@ $<

shmset:shmset.o
	$(CC) -o $@ $<

clean:
	@rm -rf shmset shmget shmset.o shmget.o
