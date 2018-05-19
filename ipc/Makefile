
CC = gcc
C_FLAGS = -c

.PHONY: ipcget clean

ipcget:ipcget.o
	$(CC) -o $@ $<

clean:
	@rm -rf ipcget.o ipcget
