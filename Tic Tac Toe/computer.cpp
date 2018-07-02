// Aaron Liszt
// computer.cpp
// defines functions for the computer class

#include "computer.h"

Computer::Computer(){}

// Returns a random number between 0-8, which is the computers selection of a position on the board 
int Computer::choosePosition(){ 
	int randNum;
	randNum = rand() % 9;
	return randNum;
}

// Returns either 'C' to continue playing or 'E' to exit the game when the computer must decied to cash out or not
// Based on a randomly generated range of numbers.
char Computer::continuePlay(){
	int randNum;
	randNum = rand() % 100 + 1;
	
	if(randNum < 50)
		return 'C';
	else
		return 'E';
}
