sinclude ./env.mk

RM = rm -rf
MKDIR = mkdir
C_FLAGS = -c

INC = -Iinc

ifeq (${MFLAG} ,yes)
C_FLAGS += -DDEBUG
C_FLAGS += -DDDD
endif


.PHONY:all clean run

all:target

target: obj  obj/main.o
	gcc -o $@ ${word 2,$^} -lpthread

obj:
	${MKDIR} $@

obj/main.o:src/test_main.c inc/test_main.h
	${CC} ${C_FLAGS} ${INC} -o $@ $<


clean:
	${RM} obj
	${RM} target

run:
	./target
