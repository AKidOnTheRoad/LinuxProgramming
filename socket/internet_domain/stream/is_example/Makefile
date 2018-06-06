
CC = gcc
C_FLAGS = -c -I.

.PHONY: is_sv is_cl all clean

all:is_sv is_cl 

is_sv:is_xfr_sv.o
	$(CC) -o $@ $<

is_cl:is_xfr_cl.o
	$(CC) -o $@ $<

clean:
	@rm -rf is_sv is_cl is_xfr_sv.o is_xfr_cl.o
