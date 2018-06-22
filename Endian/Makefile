
OBJ=obj/
SRC=src/
INC=inc/
EXE=exe/
MKDIR=mkdir

CFLAGS= -c -I$(INC)

.PHONY:all target clean 

all:target

target:$(OBJ)  $(OBJ)TestEndian.o
	gcc -o $@ ${word 2,$^}

$(OBJ):
	@$(MKDIR) $@

$(OBJ)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -o $@ $<

#$(OBJ)target.o:$(SRC)TestEndian.c $(INC)TestEndian.h
#	gcc -c -I$(INC) -o $@ $<

clean:
	@rm -rf $(OBJ)
	@rm -rf target

