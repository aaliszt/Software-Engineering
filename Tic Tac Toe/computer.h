// Aaron Liszt
// computer.h
// Outlines computer class

#ifndef COMPUTER
#define COMPUTER

#include "player.h"
#include <stdlib.h>

class Computer : public Player{
public:
	Computer();
	int choosePosition(); // Randomly selects a position on the board (0-8) to place a piece
	char continuePlay();  // Randomly selects if the computer continues playing or cashes out
};

#endif
