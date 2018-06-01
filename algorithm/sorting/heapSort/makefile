SRC=main.c
OBJ=${SRC:.c=.o}
EXE=heap
LIB=-lm
INC=


CC=gcc
LD=gcc
CCFLAG= -g
LDFLAG= -g

$(EXE):$(OBJ)
	$(LD) -o $(EXE) $(LDFLAG) $(OBJ) $(LIB)
	ctags  --file-scope=no ./*

$(OBJ):$(SRC)
	$(CC) -c $(CCFLAG) $(SRC)

clean:
	rm -f $(OBJ)
cleanall:
	rm -f $(OBJ)
	rm -f $(EXE)
cleanback:
	rm -f *~
