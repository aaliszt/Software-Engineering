// Aaron Liszt
// board.h
// Function definitions for the board class

#include "board.h"
#include <iostream>
#include <vector>

// 'Empty' the board of pieces (set all spots to ' ')
void Board::resetBoard(){
        for(int i = 0; i < Vboard.size(); ++i)
                Vboard[i] = ' ';
}

// Default Constructor
Board::Board(){ Vboard = std::vector<char>(9); resetBoard(); }

// Check if a player has won or tied. If a player wins return their repective piece (X or O),
// if there is a tie (full board) return T, otherwise return N (no win).
char Board::checkWin(){
	// ALL WINS CONDITIONS
	if (Vboard[0] != ' ' && Vboard[1] != ' ' && Vboard[2] != ' ' && Vboard[0] == Vboard[1] && Vboard[0] == Vboard[2])
        	return Vboard[0];
    	if (Vboard[3] != ' ' && Vboard[4] != ' ' && Vboard[5] != ' ' && Vboard[3] == Vboard[4] && Vboard[3] == Vboard[5])
        	return Vboard[3];
    	if (Vboard[6] != ' ' && Vboard[7] != ' ' && Vboard[8] != ' ' && Vboard[6] == Vboard[7] && Vboard[6] == Vboard[8])
        	return Vboard[6];
 
    	if (Vboard[0] != ' ' && Vboard[3] != ' ' && Vboard[6] != ' ' && Vboard[0] == Vboard[3] && Vboard[0] == Vboard[6])
        	return Vboard[0];
    	if (Vboard[1] != ' ' && Vboard[4] != ' ' && Vboard[7] != ' ' && Vboard[1] == Vboard[4] && Vboard[1] == Vboard[7])
        	return Vboard[1];
    	if (Vboard[2] != ' ' && Vboard[5] != ' ' && Vboard[8] != ' ' && Vboard[2] == Vboard[5] && Vboard[2] == Vboard[8])
        	return Vboard[2];
 
    	if (Vboard[0] != ' ' && Vboard[4] != ' ' && Vboard[8] != ' ' && Vboard[0] == Vboard[4] && Vboard[0] == Vboard[8])
        	return Vboard[0];
    	if (Vboard[2] != ' ' && Vboard[4] != ' ' && Vboard[6] != ' ' && Vboard[2] == Vboard[4] && Vboard[2] == Vboard[6])
        	return Vboard[2];
	
	// If no one has won and there is a space on the board there cannot be a tie
	for(int i = 0; i < Vboard.size(); ++i){
		if(Vboard[i] == ' ')
			return 'N';
	}
	// If no one has won and there are no empty spaces on the board there is a tie
	return 'T';		
}

// Print out the current state of the board
void Board::draw(){
	for(int i = 1; i <= Vboard.size(); ++i){
		std::cout << Vboard[i-1] << " ";
		if(i % 3 == 0)
			std::cout << std::endl;
	}
}

// Put a piece on the board at a specified position
// Assumes that checkBoard has been called previously to see if the space is filled
void Board::addPiece(char a, int i){ Vboard[i] = a; } 

// Check if a position on the board is filled (has an X or O)
// Return TRUE if the position is filled
// Return FALSE if the position is empty
bool Board::checkBoard(int i){
	if(Vboard[i] != ' ')
		return true;
	else
		return false; 	
}
