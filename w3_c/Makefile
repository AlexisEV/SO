CC = gcc
TARGET = pipe.exe
SRC = pipe.c
OBJ = pipe.o

$(TARGET):$(OBJ)
	$(CC)  $(OBJ) -o $(TARGET)

$(OBJ):$(SRC)
	$(CC) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
