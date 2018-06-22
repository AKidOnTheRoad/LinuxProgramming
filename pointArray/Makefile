
.PHONY:all clean run

C_FLAGS = -c
MKDIR = mkdir 
RM = rm -rf
all:target
CC = gcc

target: obj obj/main.o
	$(CC) -o $@ ${word 2,$^}

obj:
	${MKDIR} obj

obj/main.o:point_main.c
	$(CC) $(C_FLAGS) -o $@ $<

clean:
	$(RM) obj
	$(RM) target

run:
	./target


