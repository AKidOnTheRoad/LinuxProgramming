
C_FLAGS = -c

all: target

target: testmain.o
	gcc -o $@ $< -lpthread

testmain.o: test_main.c test_main.h
	${CC} ${C_FLAGS} -o  $@ $< 


.PHONY: clean run
clean:
	rm -rf target;
	rm -rf *.o;
run:
	./target 
