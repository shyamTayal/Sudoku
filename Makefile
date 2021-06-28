CC = g++
CFLAGS = -g

default: game

game: sudoku.o main.o
	$(CC) $(CFLAGS) -o game sudoku.o main.o

sudoku.o: sudoku.cpp sudoku.h
	$(CC) $(CFLAGS) -c sudoku.cpp
	
main.o: main.cpp sudoku.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) game *.o *~
