all: test.o linkedlist.o
	gcc test.o linkedlist.o
	
linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

test.o: test.c linkedlist.h
	gcc -c test.c
