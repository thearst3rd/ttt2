# Makefile for Tic Tac Toe Squared
# by Terry Hearst

CFLAGS = -Wall -g

all: ttt2

ttt2: board.o ttt2.c board.h
	gcc $(CFLAGS) -o ttt2 board.o ttt2.c

board.o: board.c board.h
	gcc $(CFLAGS) -c board.c

clean:
	rm -f ttt2 *.o
