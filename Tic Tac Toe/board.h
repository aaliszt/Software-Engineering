
// Aaron Liszt
// board.h
// Header definition for board
// The board object holds all current pieces(X's and O's) & keeps track of the state of the game board

#ifndef BOARD
#define BOARD

#include <vector>

class Board{
private:
	std::vector<char> Vboard;

public:
	Board();		// Default Constructor
	void resetBoard(); 	// Clear the board (Fill with space charater)
	char checkWin();	// Checks if a player has won or tied
	void draw();		// Draw the board to the screen
	void addPiece(char a, int i);	// Adds and X or O to the board given a position
	bool checkBoard(int i);	// Check if a position on the board is filled
};

#endif

