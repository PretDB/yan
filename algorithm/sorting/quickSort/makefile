SRC=main.cpp
OBJ=${SRC:.cpp=.o}
EXE=main
LIB=
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
