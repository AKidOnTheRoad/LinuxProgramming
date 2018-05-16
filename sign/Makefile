CC = gcc
C_FLAGS = -c -o 
.PHONY:all clean

all:signal sigprocmask sigaction

signal:signal.o
	$(CC) -o $@ $<

sigprocmask:sigprocmask.o
	$(CC) -o $@ $<

sigaction:sigaction.o
	$(CC) -o $@ $<

clean:
	rm -rf signal.o signal
	rm -rf sigprocmask.o sigprocmask
	rm -rf sigaction.o sigaction
