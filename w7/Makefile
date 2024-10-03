CC = gcc
all: init.exe sem.exe sem2.exe
init.exe: init.o
	$(CC) -o init.exe init.o

sem.exe: sem.o
	$(CC) -o sem.exe sem.o

sem2.exe: sem2.o
	$(CC) -o sem2.exe sem2.o

init.o: init.c
	$(CC) -c init.c

sem.o: sem.c
	$(CC) -c sem.c

sem2.o: sem2.c
	$(CC) -c sem2.c

clean:
	rm -f *.exe *.o