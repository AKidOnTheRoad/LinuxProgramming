
CC = gcc
C_FLAGS = -c -I.

.PHONY: us_sv us_cl all clean

all:us_sv us_cl 

us_sv:us_xfr_sv.o
	$(CC) -o $@ $<

us_cl:us_xfr_cl.o
	$(CC) -o $@ $<

clean:
	@rm -rf us_sv us_cl us_xfr_sv.o us_xfr_cl.o
