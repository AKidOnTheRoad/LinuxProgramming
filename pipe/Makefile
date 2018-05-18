.PHONY: pipe fifo clean

C_FLAGS = -c 
CC = gcc

pipe:pipe_process.o
	$(CC) -o $@ $<

fifo:fifo_process.o
	$(CC) -o $@ $<

clean:
	rm -fr pipe fifo
