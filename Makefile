CC=g++
prog_file=connect_four

$(prog_file): assignment1.o prog.o
	$(CC) assignment1.o prog.o -o $(prog_file)

assignment1.o: assignment1.cpp
	$(CC) -c assignment1.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp
