CC = gcc
CFLAGS = -Wall
SRC1 = prg.c
SRC2 = signal.c
OBJ1 = prg.o
OBJ2 = signal.o

P1 = prg.exe
P2 = signal.exe

all: $(P1) $(P2)

$(P1):$(OBJ1)
	$(CC) -o $(P1) $(OBJ1)

$(P2):$(OBJ2)
	$(CC) -o $(P2) $(OBJ2)

$(OBJ1):$(SRC1)
	$(CC) -c $(SRC1) -o $(OBJ1)

$(OBJ2):$(SRC2)
	$(CC) -c $(SRC2) -o $(OBJ2)

clean:
	rm -f $(OBJ1) $(OBJ2) $(P1) $(P2)

