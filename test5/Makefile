
C_FLAGS =  -c -Wall #-g -O2 -Wall -Wunused -Wmissing-declarations -Wimplicit -Wswitch -Wcast-qual -Wcast-align -Wshadow -Waggregate-return -Wnested-externs -Wmissing-prototypes -Wstrict-prototypes -fno-common -W -ansi -Werror -Wno-unused-result -Wno-unused-but-set-variable -Wno-enum-compare -Wno-unused-but-set-parameter -Wno-address -Wno-strict-aliasing -Wno-array-bounds -Wno-unused-variable

.PHONY:all clean


all:target

target:  test.d test.o
	gcc -o $@ ${word 2,$^}

#test.o:test.c test.h
#	${CC} ${C_FLAGS} -o $@ $<

test.d:
	${CC} -MM test.c >$@

clean:
#	@echo $(basename tmp/Makefile)
	@rm -f *.o *.d 

sinclude tmp/Makefile
