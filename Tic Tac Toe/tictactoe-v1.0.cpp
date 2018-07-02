/**
    Kent State University
    CS 33901 Software Engineering 
    Fall 2017
    Project #1
    Simple Tic Tac Toe
    tictactoe-v1.0.cpp
    Source: http://paste4btc.com/enVArEWu
    Author #1: NVitanovic, https://www.youtube.com/user/NVitanovic
    Author #2: Aaron Liszt 
*/

#include <iostream>
#include <string>
#include <locale>
#include "player.h"
#include "board.h"
#include "computer.h"

int main()
{
	std::string option = "";
	bool checkOption;
	int optionNum = -1;
	Player P1;
	P1.setPiece('X'); 	// Player 1 is X's
	Player P2;
	P2.setPiece('O'); 	// Player 2 is O's 
	Board ttt_board;	
	int current_Player = 1;
	Computer C1;
	C1.setPiece('O');	// Computer is O's

	while(optionNum != 3){
		std::cout << "\nWelcome to Tic Tac Toe! What would you like to do: " << std::endl;
		std::cout << "1) Player vs Player Game (2 players)\n";
		std::cout << "2) Player vs Computer Game (1 player)\n";
		std::cout << "3) Exit Game\n";
		
		checkOption = true;
		while(checkOption){
			std::cout << "Enter your selection number '1', '2', or '3' (without ''): ";
			std::cin >> option;
			std::cout << "\n\n\n";
			
			if(option.length() > 1){
				std::cout << "Please enter a valid selection mumber!\n";
				continue;
			}
			if(option[0] < 49 || option[0] > 51){
				std::cout << "Please enter a valid selection mumber!\n";
                                continue;
			}
			
			optionNum = std::stoi(option, nullptr, 0);
			checkOption = false;	
		}

		int position = -1;	// int position to place a piece selected by player
		std::string input = "";	// input from the user should be either quit or a board position
		switch(optionNum){
			case 1: // PLAYER VS PLAYER GAME
				while(position != 10){
					for(int i = 1; i <= 9; ++i){
						std::cout << i-1 << " ";
						if(i % 3 == 0)		
							std::cout << std::endl;
					}
					std::cout << std::endl;
					ttt_board.draw();
					std::cout << std::endl << "P1\tTIES\tP2" << std::endl;
					std::cout << P1.getWins() << "\t" << P1.getTies() << "\t" << P2.getWins() << std::endl;
					
					bool checkLocation = true;
					while(checkLocation){ // Run until the player enters an empty location or 'quit'
						std::cout << "Player " << current_Player << " Select a position (0-8) as '0', '1', '2'... to place your piece OR enter 'quit' to exit: ";
						std::cin >> input;
						std::cout << "\n\n\n";
					
						if(input == "quit")
							break;
						if(input.length() > 1){// Valid input should only be one character or 'quit'
							std::cout << "Please enter a valid position!" << std::endl;
							continue;						
						}
						if(input[0] < 48 || input[0] > 56){// Check ASCII values to see if single char string is within 0-8
							std::cout << "Please enter a valid position!" << std::endl;
                                                	continue;
						}
						
						position = std::stoi(input, nullptr, 0);
						if(ttt_board.checkBoard(position))
							std::cout << "This position is is full! Please enter a valid position!" << std::endl;
						else
							checkLocation = false;				
					}
					
					if(input == "quit")
						break;
								
					if(current_Player == 1)
						ttt_board.addPiece(P1.getPiece(), position);
					else
						ttt_board.addPiece(P2.getPiece(), position);
					
	
					char checkBoard = ' ';
		 			checkBoard = ttt_board.checkWin(); //Check if any player has won
					
					switch(checkBoard){
						case 'X':
							P1.setWins(P1.getWins()+1);
							P1.setStreak(P1.getStreak()+1);
							P2.setStreak(0);
							ttt_board.draw();
							ttt_board.resetBoard();
							std::cout << "Player 1 (X) wins!\n\n\n";
							checkBoard = ' ';
							break;
						case 'O':
							P2.setWins(P2.getWins()+1);
							P2.setStreak(P2.getStreak()+1);
							P1.setStreak(0);
							ttt_board.draw();
							ttt_board.resetBoard();
							std::cout << "Player 2 (O) wins!\n\n\n";
							checkBoard = ' ';
							break;
						case 'T':
							P1.setTies(P1.getTies()+1);
							P2.setTies(P2.getTies()+1);
							P1.setStreak(0);
							P2.setStreak(0);
							ttt_board.draw();
							ttt_board.resetBoard();
							std::cout << "Tie! No one wins!\n\n\n";
							checkBoard = ' ';
							break;
						case 'N':				
							break;
						default:
							break;
					}
					
					char cont = ' '; // determines if the game will continue after 3,6 and 9 win streaks
					if((P1.getStreak() == 3 && P1.getCash() != 300000) || (P1.getStreak() == 6 && P1.getCash() != 600000) || (P1.getStreak() == 9 && P1.getCash() != 900000) || (P2.getStreak() == 3 && P2.getCash() != 300000) || (P2.getStreak() == 6 && P2.getCash() != 600000) || (P2.getStreak() == 9 && P2.getCash() != 900000)){
						if(current_Player == 1){
							std::cout << "Player 1 is on a " << P1.getStreak() << " win streak! Here's $300K for your streak!" << std::endl;
							P1.setCash(P1.getCash()+300000);
							std::cout << "Player 1 now has $" << P1.getCash() << std::endl;
						}
						else{
							std::cout << "Player 2 is on a " << P2.getStreak() << " win streak! Here's $300K for your streak!" << std::endl;
                                                        P2.setCash(P2.getCash()+300000);
                                                        std::cout << "Player 2 now has $" << P2.getCash() << std::endl;
						}
						
						while(cont != 'C' && cont != 'E'){
							std::cout << "Enter 'C' to continue playing OR 'E' to exit for a fresh start: ";
							std::cin >> cont;
							std::cout << std::endl;
			
							if(cont != 'E' && cont != 'C')
								std::cout << "Please enter a valid input E or C (case-sensitive)!" << std::endl;
						}	
					}
					if(cont == 'E'){ // If cont = E player want to exit the game
						cont = ' ';
						break;
					}
					
					if(P1.getStreak() == 10 || P2.getStreak() == 10){
						if(current_Player == 1)
							std::cout << "Player 1 has won 10 straight games! Player 1 wins $1,000,000!" << std::endl << "Game Over!" << std::endl;
						else
							std::cout << "Player 2 has won 10 straight games! Player 2 wins $1,000,000!" << std::endl << "Game Over!" << std::endl;
						break;
					}
					
					// TogglePlayer
					if(current_Player == 1)
						current_Player = 2;
					else
						current_Player = 1;
				}
				ttt_board.resetBoard();
				P1.setWins(0);
				P2.setWins(0);
				P1.setTies(0);
				P2.setTies(0);
				P1.setStreak(0);
				P2.setStreak(0);
				P1.setCash(0);
				P2.setCash(0);
				current_Player = 1;			
				break;
			case 2://PLAYER VS COMPUTER GAME
				while(position != 10){
					if(current_Player == 1){
						for(int i = 1; i <= 9; ++i){
                                       			std::cout << i-1 << " ";
                                                	if(i % 3 == 0)
                                                        	std::cout << std::endl;
                                        	}
                                        	std::cout << std::endl;
						ttt_board.draw();

                                        	std::cout << std::endl << "P1\tTIES\tCPU" << std::endl;
                                        	std::cout << P1.getWins() << "\t" << P1.getTies() << "\t" << C1.getWins() << std::endl;
					}

     			                bool checkLocation = true;
					if(current_Player == 1){
                                        	while(checkLocation){ // Run until the player enters an empty location or 'quit'
                                                	std::cout << "Player 1 Select a position (0-8) as '0', '1', '2'... to place your piece OR enter 'quit' to exit: ";
                                                	std::cin >> input;
                                                	std::cout << "\n\n\n";

                                                	if(input == "quit")
                                                        	break;
                                                	if(input.length() > 1){// Valid input should only be one character or 'quit'
                                                        	std::cout << "Please enter a valid position!" << std::endl;
                                                        	continue;
                                                	}
                                                	if(input[0] < 48 || input[0] > 56){// Check ASCII values to see if single char string is within 0-8
                                                        	std::cout << "Please enter a valid position!" << std::endl;
                                                        	continue;
                                                	}

                                                	position = std::stoi(input, nullptr, 0);
                                                	if(ttt_board.checkBoard(position))
                                                        	std::cout << "This position is is full! Please enter a valid position!" << std::endl;
                                                	else
                                                        	checkLocation = false;
                                        	}
					}				

                                        if(input == "quit")
                                                break;

                                        if(current_Player == 1)
                                                ttt_board.addPiece(P1.getPiece(), position);
                                        else{
						int CPU_pos = C1.choosePosition(); 
						while(ttt_board.checkBoard(CPU_pos))
							CPU_pos = C1.choosePosition();
						
                                                ttt_board.addPiece(C1.getPiece(), CPU_pos);
					}

                                        char checkBoard = ' ';
                                        checkBoard = ttt_board.checkWin(); //Check if any player has won

                                        switch(checkBoard){
                                                case 'X':
                                                        P1.setWins(P1.getWins()+1);
                                                        P1.setStreak(P1.getStreak()+1);
                                                        C1.setStreak(0);
                                                        ttt_board.draw();
                                                        ttt_board.resetBoard();
                                                        std::cout << "Player 1 (X) wins!\n\n\n";
							std::cout << "Computer gets the first turn!\n";
                                                        checkBoard = ' ';
                                                        break;
                                                case 'O':
                                                        C1.setWins(C1.getWins()+1);
                                                        C1.setStreak(C1.getStreak()+1);
                                                        P1.setStreak(0);
                                                        ttt_board.draw();
                                                        ttt_board.resetBoard();
                                                        std::cout << "Computer (O) wins!\n\n\n";
                                                        checkBoard = ' ';
                                                        break;
                                                case 'T':
                                                        P1.setTies(P1.getTies()+1);
                                                        C1.setTies(C1.getTies()+1);
                                                        P1.setStreak(0);
                                                        C1.setStreak(0);
                                                        ttt_board.draw();
                                                        ttt_board.resetBoard();
                                                        std::cout << "Tie! No one wins!\n\n\n";
                                                        checkBoard = ' ';
                                                        break;
                                                case 'N':
                                                        break;
						default:
							break;
					}
				
                                        char cont = ' '; // determines if the game will continue after 3,6 and 9 win streaks
                                        if((P1.getStreak() == 3 && P1.getCash() != 300000) || (P1.getStreak() == 6 && P1.getCash() != 600000) || (P1.getStreak() == 9 && P1.getCash() != 900000) || (C1.getStreak() == 3 && C1.getCash() != 300000) || (C1.getStreak() == 6 && C1.getCash() != 600000) || (C1.getStreak() == 9 && C1.getCash() != 900000)){
                                                if(current_Player == 1){
                                                        std::cout << "Player 1 is on a " << P1.getStreak() << " win streak! Here's $300K for your streak!" << std::endl;
                                                        P1.setCash(P1.getCash()+300000);
                                                        std::cout << "Player 1 now has $" << P1.getCash() << std::endl;
                                                }
                                                else{
                                                        std::cout << "The Computeris on a " << C1.getStreak() << " win streak!" << std::endl;
                                                        C1.setCash(C1.getCash()+300000);
                                                        std::cout << "The Computer now has $" << C1.getCash() << std::endl;
                                                }
						
						if(current_Player == 1){
                                                	while(cont != 'C' && cont != 'E'){
                                                        	std::cout << "Enter 'C' to continue playing OR 'E' to exit for a fresh start: ";
                                                        	std::cin >> cont;
                                                        	std::cout << std::endl;

                                                        	if(cont != 'E' && cont != 'C')
                                                                	std::cout << "Please enter a valid input E or C (case-sensitive)!" << std::endl;
                                                	}
						}
						else
							cont = C1.continuePlay();

                                        }
                                        if(cont == 'E'){ // If cont = E player want to exit the game
                                                cont = ' ';
                                                break;
                                        }

                                        if(P1.getStreak() == 10 || C1.getStreak() == 10){
                                                if(current_Player == 1)
                                                        std::cout << "Player 1 has won 10 straight games! Player 1 wins $1,000,000!" << std::endl << "Game Over!" << std::endl;
                                                else
                                                        std::cout << "The Computer has won 10 straight games! It wins $1,000,000!" << std::endl << "Game Over!" << std::endl;
                                                
						break;
                                    	}

                                        // TogglePlayer
                                        if(current_Player == 1)
                                                current_Player = 2;
                                        else
                                                current_Player = 1;
                                }
                                ttt_board.resetBoard();
                                P1.setWins(0);
                                C1.setWins(0);
                                P1.setTies(0);
                                C1.setTies(0);
                                P1.setStreak(0);
                                C1.setStreak(0);
				P1.setCash(0);
				C1.setCash(0);
                                current_Player = 1;
				break;
			case 3://EXIT
				std::cout << "Thanks for playing, good-bye!" << std::endl;
				break;
			default:
				std::cout << "Please choose a valid option!(1-3)" << std::endl;
				break;
		}

	}
}
