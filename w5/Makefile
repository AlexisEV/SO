CC = gcc

all: pp.exe f.exe

pp.exe: pp.o
	$(CC) -o pp.exe pp.o

f.exe: f.o pp.exe
	$(CC) -o f.exe f.o

pp.o: pp.c
	$(CC) -c pp.c

f.o: f.c
	$(CC) -c f.c

clean:
	rm -f pp.exe f.exe pp.o f.o file_o.txt

clean_file:
	rm -f file_o.txt
