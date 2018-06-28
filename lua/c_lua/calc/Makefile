CC = gcc
RM = rm -rf
C_FLAGS = -c

.PHONY: clean

calc:calc.o
	$(CC) -o $@ $<  -llua -lm -ldl

clean:
	$(RM)  calc.o calc
