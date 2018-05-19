
CC = gcc
C_FLAGS = -c -I.
.PHONY:all clean msgcreate msgsend msgrecv

all: msgcreate msgsend msgrecv

msgcreate:msgcreate.o
	$(CC) -o $@ $<

msgsend:msgsend.o
	$(CC) -o $@ $<

msgrecv:msgrecv.o
	$(CC) -o $@ $<

clean:
	@rm -rf msgcreate msgsend msgrecv
