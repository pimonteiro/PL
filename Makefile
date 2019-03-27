CC = gcc
CFLAGS = -Wall -Wextra -O2 -g -Iinclude/

all: program

program: main.o article.o vector.o htmlexporter.o
	$(CC) $(CLFAGS) -o program main.o article.o vector.o htmlexporter.o

main.o: main.c article.h vector.h htmlexporter.h
	$(CC) $(CFLAGS) -o main.o -c main.c

article.o: article.c article.h
	$(CC) $(CFLAGS) -o article.o -c article.c

vector.o: vector.c vector.h article.h
	$(CC) $(CFLAGS) -o vector.o -c vector.c

htmlexporter.o: htmlexporter.c htmlexporter.h vector.h artice.h
	$(cc) $(FLAGS) -o htmlexporter.o -c htmlexporter.c

clean:
	rm -rf *.o
	rm program
