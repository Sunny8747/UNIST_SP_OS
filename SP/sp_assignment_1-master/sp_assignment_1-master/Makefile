HEADER=LRU.h
CC=gcc
CFLAGS=-I.
OBJ=LRU.o

default:
	make clean
	make lru 

LRU.o: LRU.c $(HEADER)
	$(CC) -c LRU.c -o LRU.o 

lru: $(OBJ)
	$(CC) main.c $(OBJ) -o LRU 

clean:
	rm -f *.o
	rm -f LRU
