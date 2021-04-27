CC = gcc

my_prg: main.o sub1.o
	$(CC) main.o sub1.o -lncurses -o my_prg

main.o: main.c
	$(CC) -c main.c

sub1.o: sub1.c sub1.h
	$(CC) -c sub1.c

clean:
	rm *.o  my_prg
