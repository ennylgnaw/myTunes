all: test.o library.o linkedlist.o
	gcc -o tests test.o library.o linkedlist.o

test.o: test.c library.h linkedlist.h
	gcc -c test.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

library.o: library.c library.h linkedlist.h
	gcc -c library.c

run:
	./tests

clear:
	rm tests
	rm *.o


