// Aaron Liszt
// player.h
// Header definition for player
// The player object holds all player specific infomation

#ifndef PLAYER
#define PLAYER

class Player{
private:
	char piece_type;		// MUST be 'X' or 'O', (Default will be 'N' before initalization)
	int wins;			// # of overall wins the player has
	int win_streak;			// # of consecutive wins the player has
	int cash;			// Cash the player has won
	int ties;			// # of ties the player has
public:
	// Default Constructor
	Player(){ piece_type = 'N'; wins = 0; win_streak = 0; cash = 0; ties = 0;}
	
	// Getter & Accessor functions
	char getPiece() { return piece_type; }
	void setPiece(char c) { piece_type  = c; }

	int getWins(){ return wins; }
	void setWins(int i){ wins = i; }

	int getStreak(){ return win_streak; }
	void setStreak(int i){ win_streak = i; }

	int getCash(){ return cash; }
	void setCash(int i){ cash = i; }

	int getTies(){ return ties; }
	void setTies(int i){ ties = i; }
};

#endif
