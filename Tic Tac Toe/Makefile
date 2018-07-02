# Aaron Liszt 9 / 16 / 2017 Makefile for tictactoe project

output: tictactoe-v1.0.o player.o board.o computer.o
	g++ tictactoe-v1.0.o player.o board.o computer.o -Wall -std=c++11 -w -o tictactoe 

tictactoe-v1.0.o: tictactoe-v1.0.cpp
	g++ -Wall -std=c++11 -c -w tictactoe-v1.0.cpp

player.o: player.cpp player.h
	g++ -Wall -std=c++11 -c -w player.cpp

board.o: board.cpp board.h
	g++ -Wall -std=c++11 -c -w board.cpp

computer.o: computer.cpp computer.h
	g++ -Wall -std=c++11 -c -w computer.cpp

clean:
	rm *.o tictactoe
