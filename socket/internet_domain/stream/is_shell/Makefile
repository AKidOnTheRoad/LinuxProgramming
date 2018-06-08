
CC = gcc
C_FLAGS = -c -I.

.PHONY: is_shell_sv is_shell_cl all clean

all:is_shell_sv is_shell_cl 

is_shell_sv:is_shell_sv.o
	$(CC) -o $@ $<

is_shell_cl:is_shell_cl.o
	$(CC) -o $@ $<

clean:
	@rm -rf is_shell_sv is_shell_cl is_shell_sv.o is_shell_cl.o
