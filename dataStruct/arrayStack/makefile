SRC=./main.c ./stack.c
OBJ=${SRC:.c=.o}
EXE=main
LIB=
INC=


CC=gcc
LD=gcc
CCFLAG= -g
LDFLAG=

$(EXE):$(OBJ)
	$(LD) -o $(EXE) $(LDFLAG) $(OBJ) $(LIB)

$(OBJ):$(SRC)
	$(CC) -c $(CCFLAG) $(SRC)

clean:
	rm -f $(OBJ)
cleanall:
	rm -f $(OBJ)
	rm -f $(EXE)
cleanback:
	rm -f *~
