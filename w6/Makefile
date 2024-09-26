CC = gcc
CC+ = g++

all: p.exe rcv.exe send.exe

p.exe: p.o
	$(CC) -o p.exe p.o

rcv.exe: rcv.o
	$(CC+) -o rcv.exe rcv.o

send.exe: send.o
	$(CC) -o send.exe send.o

p.o: p.c
	$(CC) -c p.c

rcv.o: rcv.cpp
	$(CC+) -c rcv.cpp

send.o: send.c
	$(CC) -c send.c

clean:
	rm -f *.exe *.o
