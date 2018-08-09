
CC = gcc
.PHONY: create clean count 
exe:
	mkdir exe

create:thread_create.o
	$(CC) -o exe/$@ $< -lpthread
count:thread_count.o
	$(CC) -o exe/$@ $< -lpthread

cancel:thread_cancel.o
	$(CC) -o exe/$@ $< -lpthread

clean:
	rm -rf thread_create.o exe/*
	rm -rf thread_count.o 
	rm -rf thread_cancel.o 
