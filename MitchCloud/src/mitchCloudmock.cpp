//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: mitchCloudmock.cpp
//Create Date: Nov 8, 2017
//Author: Aaron Liszt
//Version: 2.0
//------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <cmath>
#include "clerk.h"
#include "item.h"
#include "cart.h"
#include "menu.h"
#include "logger.h"
#include "customer.h"
#include "manager.h"
#include "analist.h"
#include "userList.h"
#include "deliveryMethod.h"
#include "order.h"
#include "orderList.h"
#include "inventory.h"
#include "taxCalculator.h"

int main(){
	// ITEM LIST INITALIZATION
	item I1; I1.setItemName("1 Vanilla Scoop"); I1.setItemCost(3.75); I1.setID("I1");		// Vanilla Single Scoop
	item I2; I2.setItemName("1 Chocolate Scoop"); I2.setItemCost(3.75); I2.setID("I2");		// Chocolate Single Scoop
	item I3; I3.setItemName("1 Blue Cosmo Scoop"); I3.setItemCost(3.75); I3.setID("I3");		// Blue Cosmo Single Scoop
	item I4; I4.setItemName("1 Fresh Mint Scoop"); I4.setItemCost(3.75); I4.setID("I4");		// Fresh Mint Single Scoop
	item I5; I5.setItemName("1 Cookie Dough Scoop"); I5.setItemCost(3.75); I5.setID("I5");		// Cookie Dough Single Scoop
	item I6; I6.setItemName("1 Turtle Sundae"); I6.setItemCost(5.25); I6.setID("I6");		// Turtle Sundae
	item I7; I7.setItemName("1 Root Beer Float"); I7.setItemCost(5.25); I7.setID("I7");		// Root Beer Float
	item I8; I8.setItemName("1 Bannana Split"); I8.setItemCost(5.95); I8.setID("I8");		// Bannana Split
	item I9; I9.setItemName("1 Vanilla Bean Cake"); I9.setItemCost(29.95); I9.setID("I9");		// Vanilla Bean Cake
	item I10; I10.setItemName("1 Cookies & Cream Cake"); I10.setItemCost(29.95); I10.setID("I10");	// Cookies & Cream Cake

	// MENU INITALIZATION
	menu fullMenu;			menu filterMenu;		
	fullMenu.addMenuItem(I1);	filterMenu.addMenuItem(I1);
	fullMenu.addMenuItem(I2);	filterMenu.addMenuItem(I2);
	fullMenu.addMenuItem(I3);	filterMenu.addMenuItem(I3);
	fullMenu.addMenuItem(I4);	filterMenu.addMenuItem(I4);
	fullMenu.addMenuItem(I5);	filterMenu.addMenuItem(I5);
	fullMenu.addMenuItem(I6);
	fullMenu.addMenuItem(I7);
	fullMenu.addMenuItem(I8);
	fullMenu.addMenuItem(I9);
	fullMenu.addMenuItem(I10);

	// INVENTORY INITIALIZATION
	inventory INV;
	INV.addItem(I1);	INV.addMaterial(std::string("BANNANAS"));
        INV.addItem(I2);	INV.addMaterial(std::string("VANILLA BEANS"));
        INV.addItem(I3);        INV.addMaterial(std::string("COCO POWDER(lbs)"));
        INV.addItem(I4);        INV.addMaterial(std::string("BLUE DYE(gal)"));
        INV.addItem(I5);        INV.addMaterial(std::string("CHOCOLATE CHIPS"));
        INV.addItem(I6);        INV.addMaterial(std::string("EGGS"));
        INV.addItem(I7);        INV.addMaterial(std::string("MINT LEAFS"));
        INV.addItem(I8);        INV.addMaterial(std::string("MILK(gal)"));
        INV.addItem(I9);        INV.addMaterial(std::string("SUGAR(lbs)"));
        INV.addItem(I10);       INV.addMaterial(std::string("ROOT BEER(gal)"));
        INV.setItemAMT(1000);	INV.setMaterialAMT(100);
        INV.setItemAMT(300);   	INV.setMaterialAMT(300);
        INV.setItemAMT(250);   	INV.setMaterialAMT(20);
        INV.setItemAMT(750);   	INV.setMaterialAMT(10);
        INV.setItemAMT(500);   	INV.setMaterialAMT(10000);
        INV.setItemAMT(0);   	INV.setMaterialAMT(500);
        INV.setItemAMT(0);   	INV.setMaterialAMT(150);
        INV.setItemAMT(0);   	INV.setMaterialAMT(135);
        INV.setItemAMT(50);   	INV.setMaterialAMT(100);
        INV.setItemAMT(25);	INV.setMaterialAMT(50);

	int option = -1;	// in for main looping menu
	clerk C1;		// TESTING CLERK "ICE" with password "CUBE"
	C1.setName(std::string("ICE"));
	C1.setPass(std::string("CUBE"));
	C1.setN(std::string("Aaron"));
	C1.setPhone(std::string("555-555-4321"));
	C1.setHours(24);

	customer CC1;		// TESTING CUSTOMER "FLOYD" with password "THINICE"
	CC1.setName(std::string("FLOYD"));
	CC1.setPass(std::string("THINICE"));
	CC1.setN(std::string("Allie"));
	CC1.setGender('F');
	CC1.setPhone("987-654-3210");
        CC1.setAddress(std::string("4321 Street Lane Drive"));
        CC1.setAge(18);	

	manager M1;		// TESTING MANAGER "METALLICA" with password "UNDERICE"
	M1.setName(std::string("METALLICA"));
	M1.setPass(std::string("UNDERICE"));
	M1.setN(std::string("Happy"));
	M1.setHours(1);

	analist A1;			// SALES ANALIST "ZEPPELIN" with password "ICEANDSNOW"
	A1.setName(std::string("ZEPPELIN"));
	A1.setPass(std::string("ICEANDSNOW"));

	userList U1;
	U1.addUser(CC1.getName());
	U1.addUser(C1.getName());
	U1.addUser(M1.getName());
	U1.addUser(A1.getName());

	orderList O;			// ORDER LIST
	
	cart T1;
	T1.addItem(I10);
	deliveryMethod D1(std::string("PICKUP"), std::string("4321 Street Lane Drive"));
	order O1(D1, T1, std::string("FLYOD"));

	cart T2;
	T2.addItem(I1);
	T2.addItem(I4);
	deliveryMethod D2(std::string("FOOD-TRUCK"), std::string("4321 Street Lane Drive"));
	order O2(D2, T2, std::string("FLYOD"));

	cart T3;
	T3.addItem(I8);
	T3.addItem(I7);
	T3.addItem(I6);
	deliveryMethod D3(std::string("FOOD-TRUCK"), std::string("4321 Street Lane Drive"));
	order O3(D3, T3, std::string("FLYOD"));

	O.addOrder(O1);
	O.addOrder(O2);
	O.addOrder(O3);

	taxCalculator TC;	//TAX CALCULATOR

	bool loggedIn = false;	// bool for login loop
	bool validU = false;	// bool for username loop
	bool validP = false;	// bool for password loop
	std::string uname;	// store user input username
	std::string pass;	// store user input password
	int interactionType = 0; // type of user interaction with the system either 1(POS) or 2 (WEB)	
	int userType = -1; 	// Use in web interaction to mark what user logged into the system (0 = Customer, 1 = Clerk, 2 = Manager, 3 = Sales)
	int saleOP = -1;	// used in web interactions with analist
	int manOP = -1;		// used in web interactions with manager
	int cusOP = -1;		// used in web interactions with customer
	int cleOP = -1;		// used in web interactions with clerk
	bool validItemID = false;   // used in web for add/remove item
	int uitemID = -1;	// used in web o store item id
	char conCheck = 'B';	// used in web to confirm or deny checkout
	int payOP = -1;		// used in web to select payment method
	deliveryMethod CD; 	// used in web checkout to store delivery info
	int dOP = -1;		// used in web checout to choose delivery method
	int pOP = -1;		// used in web client with clerk to choose profile information to edit
	std::string info;	// used in web vlient with clerk to store new profile infromation
	order CO;		// used to store customer order
	logger L1;		// LOGGER
	
	while(!loggedIn){
		std::cout << "Welcome to MitchCloud!\n";
		
		while(interactionType != 1 && interactionType != 2){		
			std::cout << "\nPlease choose your interaction type: \n";
			std::cout << "1. POS Testing\n";
			std::cout << "2. Website Testing\n";
			std::cout << "Enter your selection as '1' or '2'(without ''): ";
			std::cin >> interactionType;
			std::cout << std::endl;

			if(interactionType != 1 && interactionType != 2){
				std::cout << "Please choose a valid interaction type 1 OR 2!\n";	
		}
		switch(interactionType){
			case 1:			// POS Testing Client
				while(!validU){		// Loop until valid username is entered 
					std::cout << "Please enter your username (case-sensitive): ";
					std::cin >> uname;
					if(uname == C1.getName())// If username exists we are done
						validU = true;
					else
						std::cout << "\nInvalid username! Please enter a username such as ICE...\n";
				}
				std::cout << std::endl;
				while(!validP){		// Loop until the user enters the correct password for their username
					std::cout << "Please enter your password (case-sensitive): ";
					std::cin >> pass;
					if(pass == C1.getPass()) // If password matches username we are done
						validP = true;
					else
						std::cout << "\nPassword for " << C1.getName() << " is incorrect!\n"; 
				}
				std::cout << std::endl;

				loggedIn = true;	// Once the user has entered their username and password they are now logged into the system
				L1.write("USER " + C1.getName() + " logged in");
				while(option != 3){	// Loop until the user enters 3 to exit the system
					std::cout << "What would you like to do?\n";
					std::cout << "1. Text File input senario\n";
					std::cout << "2. Command Line input\n";
					std::cout << "3. Exit\n";
					std::cout << "Enter your selection as '1' or '2' (without ''): ";
					std::cin >> option;
	
					std::string filename;	// Store user input txt file name
					std::string line;	// Store lines read in from txt file
					std::ifstream txtfile;  // input stream from specified txt file
					int op = -1;		// int for command line looping menu (CASE 2)

					switch(option){
						case 1:		// TEXT FILE INPUT
							L1.write("USER " + C1.getName() + " selected text file input mode");
							std::cout << "Enter the name of the text file to read from: ";
							std::cin >> filename;
						
							txtfile.open(filename);
							if(txtfile.is_open()){ // Read every line from the specified file
								L1.write("USER " + C1.getName() + " opened text file  senario -" + filename);
								while(!txtfile.eof()){
									if(!txtfile.eof())
										getline(txtfile, line);
	
									if(line[0] == 'A'){ // If line starts with A we are adding to cart
										C1.uCart.addItem(fullMenu.getMenuItem(line.substr(2, line.length())));
										std::cout << "Added item " << line.substr(2, line.length()) << " to the cart!\n";
									} // If line starts with R we are removing from cart
									else if(line[0] == 'R'){
										C1.uCart.removeItem(fullMenu.getMenuItem(line.substr(2, line.length())));
										std::cout << "Removed item(s) " << line.substr(2, line.length()) << " from the cart!\n";
									}
									else if(line[0] == '$')	// If line starts with $ we are geting the cost of the cart
										std::cout << "getCost - Cart cost: $" << C1.uCart.getTotal() << "\n";
									else if(line[0] == 'P'){ // If the line starts with P we are printing the carts contents
										std::cout << "getItems - Cart contains:\n";
										C1.uCart.getItems();
									}	// Otherwise simply print whats on the line (no command given)
									else{
										std::cout << line << "\n";
									}
									std::this_thread::sleep_for (std::chrono::seconds(1)); // Pause between each line to observe
								}
							}
							else{	// File failed to open
								std::cout << "Failed to open file!\n";
								L1.write("USER " + C1.getName() + " failed to open file -" + filename);
							}
							C1.uCart.emptyCart();
							break;
						case 2:		// COMMAND LINE INPUT
							L1.write("USER " + C1.getName() + " selected command line input mode");
							while(op != 7){ // Loop until the user enters 7 to exit
								std::cout << "\nWhat would you like to do?\n";
								std::cout << "1. Display Menu\n";
								std::cout << "2. Add item to cart\n";
								std::cout << "3. Remove item from cart\n";
								std::cout << "4. Display cart\n";
								std::cout << "5. Display cart cost\n";
								std::cout << "6. Checkout Order\n";
								std::cout << "7. Logout\n";
								std::cout << "Enter your selection 1-7 as '1' etc... (without ''): ";
								std::cin >> op;
								std::cout << std::endl;

								int itemID = -1; // Item ID (1-10) matching up to an item in the display menu in case 1
								bool validID = false;
								int paymentOP = -1;	// Number 1-3 to choose payment option
								char confirm = 'Q'; // Either Y/N, user must confirm carts contents
	
								double taxTotal = C1.uCart.getTotal() + (C1.uCart.getTotal() * .0575); // Total cost with 5.75% tax
                	                                	taxTotal = floor(taxTotal*100+.5)/100;
				
								switch(op){
									case 1: // DISPLAY MENU
										L1.write("USER " + C1.getName() + " requested the menu be displayed.");
										std::cout << "\nICE CREAM (1 Scoop)\t SPECIALS\t\t\t CAKES\n";
										std::cout << "1 Vanilla $3.75\t\t 6 Turtle Sundae $5.25\t\t 9 Vanilla Bean $29.95\n";
										std::cout << "2 Chocolate $3.75\t 7 Root Beer Float $5.25\t 10 Cookies & Cream $29.95\n"; 
										std::cout << "3 Blue Cosmo $3.75\t 8 Bannana Split $5.95\n"; 
										std::cout << "4 Fresh Mint $3.75\n";
										std::cout << "5 Cookie Dough $3.75\n";
										L1.write("Menu was displayed to screen");
										break;
									case 2: // ADD ITEM TO CART
										while(!validID){
											std::cout << "Enter an item ID (1-10) from the menu as '1' etc...: ";
											std::cin >> itemID;
											std::cout << std::endl;
									
											if(itemID > 10 || itemID < 1)
												std::cout << "Please enter a valid ID 1-10!\n";
											else
												validID = true;
										}
										validID = false;
										
										switch(itemID){ // itemID and item should be in the same class later
											case 1:
												C1.uCart.addItem(I1);
												L1.write("USER " + C1.getName() + " added " + I1.getItemName() + " to their cart");		
												break;
											case 2:
												C1.uCart.addItem(I2);
												L1.write("USER " + C1.getName() + " added " + I2.getItemName() + " to their cart");			
												break;
											case 3:
												C1.uCart.addItem(I3);
												L1.write("USER " + C1.getName() + " added " + I3.getItemName()  + " to their cart");
												break;
											case 4:
												C1.uCart.addItem(I4);
												L1.write("USER " + C1.getName() + " added " + I4.getItemName()  + " to their cart");
												break;
											case 5:
												C1.uCart.addItem(I5);
												L1.write("USER " + C1.getName() + " added " + I5.getItemName()  + " to their cart");
												break;
											case 6:
												C1.uCart.addItem(I6);
												L1.write("USER " + C1.getName() + " added " + I6.getItemName()  + " to their cart");
												break;
 											case 7:
												C1.uCart.addItem(I7);
												L1.write("USER " + C1.getName() + " added " + I7.getItemName()  + " to their cart");
												break;
											case 8:
												C1.uCart.addItem(I8);
												L1.write("USER " + C1.getName() + " added " + I8.getItemName()  + " to their cart");
												break;
											case 9:
												C1.uCart.addItem(I9);
												L1.write("USER " + C1.getName() + " added " + I9.getItemName()  + " to their cart");
												break;
											case 10:
												C1.uCart.addItem(I10);
												L1.write("USER " + C1.getName() + " added " + I10.getItemName()  + " to their cart");
												break;
										}
										std::cout << "Item added to cart!\n";
										break;
									case 3:	// REMOVE ITEM FROM CART
										while(!validID){
                                        	                	                std::cout << "Enter an item ID (1-10) from the menu as '1' to remove from the cart: ";
                                                	                	        std::cin >> itemID;
 		                                                                       	std::cout << std::endl;
	
        	    	                                                            if(itemID > 10 || itemID < 1)
                		                                                                std::cout << "Please enter a valid ID 1-10!\n";
                        		                                                else
                                		                                                validID = true;
                                        		                        }
                                                		                validID = false;
										
										switch(itemID){
											case 1:
												C1.uCart.removeItem(I1);
												L1.write("USER " + C1.getName() + " removed " + I1.getItemName()  + " from their cart");
												break;
											case 2:
												C1.uCart.removeItem(I2);
												L1.write("USER " + C1.getName() + " removed " + I2.getItemName()  + " from their cart");
                                	                	                                break;
											case 3:
												C1.uCart.removeItem(I3);
												L1.write("USER " + C1.getName() + " removed " + I3.getItemName()  + " from their cart");
                                                                	                	break;
											case 4:
												C1.uCart.removeItem(I4);
												L1.write("USER " + C1.getName() + " removed " + I4.getItemName()  + " from their cart");
              		                  	                                                break;		
											case 5:
												C1.uCart.removeItem(I5);
												L1.write("USER " + C1.getName() + " removed " + I5.getItemName()  + " from their cart");
                                                	                	                break;	
											case 6:
												C1.uCart.removeItem(I6);
												L1.write("USER " + C1.getName() + " removed " + I6.getItemName()  + " from their cart");
                	        	                                                        break;
											case 7:
												C1.uCart.removeItem(I7);
												L1.write("USER " + C1.getName() + " removed " + I7.getItemName()  + " from their cart");
                                                	        	                        break;
											case 8:
												C1.uCart.removeItem(I8);
												L1.write("USER " + C1.getName() + " removed " + I8.getItemName()  + " from their cart");
                                                                                		break;
											case 9:
												C1.uCart.removeItem(I9);
												L1.write("USER " + C1.getName() + " removed " + I9.getItemName()  + " from their cart");
                        	        	                                                break;
											case 10:
												C1.uCart.removeItem(I10);
												L1.write("USER " + C1.getName() + " removed " + I10.getItemName()  + " from their cart");
                                                        	        	                break;
										}
										std::cout << "Item(s) removed from cart!\n";
										break;
									case 4: // PRINT CART CONTENTS
										C1.uCart.getItems();
										L1.write("USER " + C1.getName() + " requested their carts contents");
										L1.write("USER " + C1.getName() + "'s cart was printed to the screen");		
										break;
									case 5: // PRINT CART COST
										std::cout << "The cost of your cart is: $" << C1.uCart.getTotal() << "\n";
										L1.write("USER " + C1.getName() + " requested their carts total cost");
										L1.write("USER " + C1.getName() + "'s total cost was printed to the screen");
										break;
									case 6:
										C1.uCart.getItems();
										L1.write("USER " + C1.getName() + " started checkout");	
										while(confirm != 'Y' && confirm != 'N'){
											std::cout << "Please confirm your order, enter 'Y' yes to confirm or 'N' no to keep shopping(without ''): ";
											std::cin >> confirm;
											std::cout << std::endl;
											
											if(confirm != 'Y' && confirm != 'N')
												std::cout << "Please enter valid input, either 'Y' or 'N'!(case-sensitive)\n";
										}
										
										if(confirm == 'Y'){
											L1.write("USER " + C1.getName() + " confirmed their carts contents");
											std::cout << "The cost of your cart with tax is: $" << taxTotal << "\n";
											L1.write("SYSTEM printed carts cost with tax to screen");
											
											std::cout << "Select your payment method\n";
											std::cout << "1. Credit\n";
											std::cout << "2. Debit\n";
											std::cout << "3. Cash\n";
											std::cout << "Enter your payment number (1-3) as 1 2 or 3: ";
											std::cin >> paymentOP;
											std::cout << std::endl;
			
											double cash = 0;
											L1.write("USER " + C1.getName() + " chose their payment method");
											switch(paymentOP){
												case 1: // CREDIT
													std::cout << "Please swipe your card.\n";
													std::cout << "Processing...\n";
													std::this_thread::sleep_for (std::chrono::seconds(1));
													std::cout << "Transaction Complete!\n";
													L1.write("USER " + C1.getName() + " checked out with credit");										
													break;
												case 2: // DEBIT
													std::cout << "Please swipe your card.\n";
                        		                                                                std::cout << "Processing...\n";
                                		                                                        std::this_thread::sleep_for (std::chrono::seconds(1));
                                        		                                                std::cout << "Transaction Complete!\n";
													L1.write("USER " + C1.getName() + " checked out with debit");	
													break;
												case 3: // CASH
													while(cash <  taxTotal){
														std::cout << "Enter cash amount: ";
														std::cin >> cash;
														std::cout << std::endl;
			
														if(cash >= taxTotal){
															std::cout << "Thank you for your payment!\n";	
															std::cout << "Change due: $" << cash -  taxTotal << "\n";
															L1.write("USER " + C1.getName() + " gave $" + std::to_string(cash) + " dollars cash");
															L1.write("USER " + C1.getName() + " recieved $" + std::to_string(cash - taxTotal) + " in change");
														}
														else{
															std::cout << "Insufficient funds! Please pay more.\n";
															L1.write("USER " + C1.getName() + " provided insufficient funds ($" + std::to_string(cash) + ")");
														}
													}
													L1.write("USER " + C1.getName() + " checked out with cash");
													break;
												default:
													std::cout << "Invalid payment option!\n";
													L1.write("USER " + C1.getName() + " chose an invalid payment option");
													break;
											} 
										}
										else{
											L1.write("USER " + C1.getName() + " canceled checkout");
											break;
										}						
				
										std::cout << "\nORDER RECIPT:\n";
										C1.uCart.getItems();
										std::cout << "Before Tax: $" << C1.uCart.getTotal() << "\n";
										std::cout << "After Tax:  $" << taxTotal<< "\n";
										std::cout << "\n\nEND OF SALE\n\n";
										C1.uCart.emptyCart();
										L1.write("SYSTEM printed recipt");
										L1.write("Sale completed");
										L1.write("USER " + C1.getName() + "'s cart was emptied");
										confirm = 'Q';
										break;
									case 7:	// LOGOUT 
										std::cout << "Logging out " << C1.getName() << "...\n";
										C1.uCart.emptyCart();
										L1.write("USER " + C1.getName() + " exited command line input mode");
										break;
									default:	// Invalid Input
										std::cout << "Please enter a vaild option 1-7!\n";
										break;
								}
							}
							break;
						case 3:
							std::cout << "Good-bye!\n";
							L1.write("USER " + C1.getName() + " logged out");
							break;
						default:
							std::cout << "Please choose a valid option!\n";
							break;
					}
			
				}
				break;
			case 2:		//WEB TESTING
				while(!validU){         // Loop until valid username is entered
                                        std::cout << "Please enter your username (case-sensitive): ";
                                        std::cin >> uname;
                                        if((uname == CC1.getName()) || (uname == C1.getName()) || (uname == A1.getName()) || (uname == M1.getName()))// If username exists we are done
                                                validU = true;
                                        else
                                                std::cout << "\nInvalid username! Please enter a username such as ICE...\n";
                                }
                                std::cout << std::endl;
                                while(!validP){         // Loop until the user enters the correct password for their username
                                        std::cout << "Please enter your password (case-sensitive): ";
                                        std::cin >> pass;
                                        if(pass == CC1.getPass()  && uname == CC1.getName()){// If password matches username we are done
                                                validP = true;
						userType = 0;	//CUSTOMER
					}
					else if(pass == C1.getPass() && uname == C1.getName()){
						validP = true;
						userType = 1;	//CLERK
					}
					else if(pass ==  M1.getPass() && uname == M1.getName()){
						validP = true;
						userType = 2;	//MANGER
					}
					else if(pass ==  A1.getPass() && uname == A1.getName()){
						validP = true;
						userType = 3;	//SALES
					}
                                        else
                                                std::cout << "\nPassword is incorrect!\n";
                                }
                                std::cout << std::endl;
				
				validU = false;
				validP = false;
				loggedIn = true;

				switch(userType){
					case 0:		// CUSTOMER LOGIN
						L1.write("CUSTOMER " + CC1.getName() + " logged in");
						while(cusOP != 9){
							std::cout << "\nWhat would you like to do?\n";
                                                        std::cout << "1. Display Menu\n";
                                                        std::cout << "2. Add item to cart\n";
                                                        std::cout << "3. Remove item from cart\n";
                                                        std::cout << "4. Display cart\n";
                                                        std::cout << "5. Display cart cost\n";
                                                        std::cout << "6. Checkout Order\n";
						        std::cout << "7. View Personal Profile\n";
							std::cout << "8. View Filtered Menu\n";
                                                        std::cout << "9. Logout\n";
                                                        std::cout << "Enter your selection 1-9 as '1' etc... (without ''): ";
							std::cin >> cusOP;
							std::cout << "\n";							
							
							switch(cusOP){
								case 1: // PRINT MENU
									L1.write("CUSTOMER " + CC1.getName() + " requested the menu");
									fullMenu.printMenu();
									L1.write("SYSTEM printed menu to screen");
									break;
								case 2: // ADD ITEM TO CART
									while(!validItemID){
                                                                                        std::cout << "Enter an item ID (1-10) from the menu as '1' etc...: ";
                                                                                        std::cin >> uitemID;
                                                                                        std::cout << std::endl;

                                                                                        if(uitemID > 10 || uitemID < 1)
                                                                                                std::cout << "Please enter a valid ID 1-10!\n";
                                                                                        else
                                                                                                validItemID = true;
                                                                        }
                                                                        validItemID = false;
				
									switch(uitemID){
										case 1:
											CC1.cCart.addItem(I1);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I1.getItemName() + " to their cart");
											break;
										case 2:
											CC1.cCart.addItem(I2);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I2.getItemName() + " to their cart");
											break;
										case 3:
											CC1.cCart.addItem(I3);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I3.getItemName() + " to their cart");
											break;
										case 4:
											CC1.cCart.addItem(I4);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I4.getItemName() + " to their cart");
											break;
										case 5:
											CC1.cCart.addItem(I5);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I5.getItemName() + " to their cart");
											break;
										case 6:
											CC1.cCart.addItem(I6);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I6.getItemName() + " to their cart");
											break;
										case 7:
											CC1.cCart.addItem(I7);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I7.getItemName() + " to their cart");
											break;
										case 8:
											CC1.cCart.addItem(I8);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I8.getItemName() + " to their cart");
											break;
										case 9:
											CC1.cCart.addItem(I9);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I9.getItemName() + " to their cart");
											break;
										case 10:
											CC1.cCart.addItem(I10);
											L1.write("CUSTOMER " + CC1.getName() + " added " + I10.getItemName() + " to their cart");
											break;
									}
									std::cout << "Item added to cart!\n";									
									break;
								case 3: // REMOVE ITEM FROM CART
									while(!validItemID){
                                                                                        std::cout << "Enter an item ID (1-10) from the menu as '1' etc...: ";
                                                                                        std::cin >> uitemID;
                                                                                        std::cout << std::endl;

                                                                                        if(uitemID > 10 || uitemID < 1)
                                                                                                std::cout << "Please enter a valid ID 1-10!\n";
                                                                                        else
                                                                                                validItemID = true;
                                                                        }
                                                                        validItemID = false;

									switch(uitemID){
										case 1:
											CC1.cCart.removeItem(I1);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I1.getItemName()  + " from their cart");
											break;
										case 2:
											CC1.cCart.removeItem(I2);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I2.getItemName()  + " from their cart");
											break;
										case 3:
											CC1.cCart.removeItem(I3);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I3.getItemName()  + " from their cart");
											break;
										case 4:
											CC1.cCart.removeItem(I4);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I4.getItemName()  + " from their cart");
											break;
										case 5:
											CC1.cCart.removeItem(I5);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I5.getItemName()  + " from their cart");
											break;
										case 6:
											CC1.cCart.removeItem(I6);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I6.getItemName()  + " from their cart");
											break;
										case 7:
											CC1.cCart.removeItem(I7);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I7.getItemName()  + " from their cart");
											break;
										case 8:
											CC1.cCart.removeItem(I8);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I8.getItemName()  + " from their cart");
											break;
										case 9:
											CC1.cCart.removeItem(I9);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I9.getItemName()  + " from their cart");
											break;
										case 10:
											CC1.cCart.removeItem(I10);
											L1.write("CUSTOMER " + CC1.getName() + " removed " + I10.getItemName()  + " from their cart");
											break;
									}
									std::cout << "Item(s) removed from cart!\n";
									break;									
								case 4: // PRINT CART
									L1.write("CUSTOMER " + CC1.getName() + "requested their cart be printed");
									CC1.cCart.getItems();
									L1.write("SYSTEM printed cart to screen");
									break;
								case 5: // PRINT CART COST
									L1.write("CUSTOMER " + CC1.getName() + "requested their cart cost be printed");
									std::cout << "The cost of your cart is: $" << CC1.cCart.getTotal() << "\n";
									L1.write("SYSTEM printed carts cost to screen");
									break;
								case 6: // CHECKOUT
									L1.write("CUSTOMER " + CC1.getName() + "started checkout");
									CC1.cCart.getItems();
									L1.write("SYSTEM printed customers cart to screen");
									while(conCheck != 'Y' && conCheck != 'N'){
										std::cout << "Please confirm your order, enter 'Y' yes to confirm or 'N' no to keep shopping(without ''): ";
										std::cin >> conCheck;
										std::cout << std::endl;
											
										if(conCheck != 'Y' && conCheck != 'N')
											std::cout << "Please enter valid input, either 'Y' or 'N'!(case-sensitive)\n";
									}
									if(conCheck == 'Y'){
										L1.write("CUSTOMER " + CC1.getName() + "confirmed thier carts contents");
										std::cout << "The cost of your cart with tax is $" << TC.giveTax(CC1.cCart.getTotal()) << "\n";
										
										std::cout << "Select your payment method\n";
										std::cout << "1.Credit\n";
										std::cout << "2.Debit\n";
										std::cout << "Enter your payment number 1 OR 2: ";
										std::cin >> payOP;
										std::cout << "\n";
										
										std::cout << "Select your delivery method\n";
                                                                                std::cout << "1.Pick-up\n";
                                                                                std::cout << "2.Deliverd\n";
                                                                                std::cout << "Enter your delivery choice 1 OR 2: ";
                                                                                std::cin >> dOP;
                                                                                std::cout << "\n";
										if(dOP == 1){
											CD.setType("PICKUP");
											L1.write("CUSTOMER " + CC1.getName() + "selected PICKUP delivery");
										}
										else{
											CD.setType("FOOD-TRUCK");
											L1.write("CUSTOMER " + CC1.getName() + "selected FOOD-TRUCK delivery");
										}
										CD.setAddress(CC1.getAddress());
										
										switch(payOP){
											case 1: // CREDIT
												std::cout << "Validating Card...\n";
												std::this_thread::sleep_for (std::chrono::seconds(1));
												std::cout << "Card Accepted!\n";
												std::cout << "Transaction Complete!\n";
												L1.write("CUSTOMER " + CC1.getName() + "checked out with credit");
												break;
											case 2: // DEBIT
												std::cout << "Validating Card...\n";
                                                                                                std::this_thread::sleep_for (std::chrono::seconds(1));
                                                                                                std::cout << "Card Accepted!\n";
                                                                                                std::cout << "Transaction Complete!\n";
												L1.write("CUSTOMER " + CC1.getName() + "checked out with debit");
                                                                                                break;
											default:
												std::cout << "INVALID PAYMENT OPTION!\n";
												break;
										}
									}
									else{
										std::cout << "Checkout Cancled!\n";
										L1.write("CUSTOMER " + CC1.getName() + "canceled checkout");
										conCheck = 'Q';
										break;
									}
									CO = order(CD, CC1.cCart, CC1.getName());
									O.addOrder(CO);

									std::cout << "\nORDER RECIPT\n";
									CC1.cCart.getItems();
									std::cout << "Before Tax: $" << CC1.cCart.getTotal() << "\n";
									std::cout << "After Tax: $" << TC.giveTax(CC1.cCart.getTotal()) << "\n";
									std::cout << "Delivery Method: " << CD.getType() << "\n";
									std::cout << "Delivery Address: " << CD.getAddress() << "\n";
									std::cout << "\n\nEND OF SALE\n\n";

									CC1.cCart.emptyCart();
									L1.write("SYSTEM printed recipt");
									L1.write("SYSTEM emptied customers cart");
									conCheck = 'Q';								
									break;
								case 7: // PRINT PROFILE
									L1.write("CUSTOMER " + CC1.getName() + "requested their profile be displayed");
									CC1.printCustomerProfile();
									L1.write("SYSTEM printed customers profile to screen");
									break;
								case 8: // PRINT FILTERED MENU
									L1.write("CUSTOMER " + CC1.getName() + "requested a filtered menu");
									std::cout << "---BASIC MENU---\n";
									filterMenu.printMenu();
									L1.write("SYSTEM printed filtered menu to screen");
									break;
								case 9: // EXIT
									std::cout << "Good-bye!\n";
									L1.write("CUSTOMER " + CC1.getName() + "logged out");
									break;
							}
						}
						break;
					case 1:		// CLERK LOGIN
						L1.write("CLERK " + C1.getName() + "logged in");
						while(cleOP != 3){
							std::cout << "Please select an option: \n";
							std::cout << "1. Edit Profile Info\n";
							std::cout << "2. View Personal Worker Profile\n";
							std::cout << "3. Logout\n";
							std::cout << "Enter your selection: ";
							std::cin >> cleOP;
							std::cout << "\n";
			
							switch(cleOP){
								case 1: // EDIT PROFILE
									L1.write("CLERK " + C1.getName() + "requested to edit their work profile");
									while(pOP != 1 && pOP != 2){
										std::cout << "What would you like to edit?\n";
										std::cout << "1. Phone Number\n";
										std::cout << "2. Name\n";
										std::cout << "Enter your selection: ";
										std::cin >> pOP;
										std::cout << "\n";
				
										if(pOP != 1 && pOP != 2)
											std::cout << "ENTER A VALID NUMBER!\n";
									}

									if(pOP == 1){ // Change phone number
										std::cout << "Please enter a new phone number: ";
										std::cin >> info;
										std::cout << "\n";
										C1.setPhone(info);
										std::cout << "Phone Number updated!\n";
										L1.write("CLERK " + C1.getName() + "changed their phone number");
									}
									else{ // Change name
										std::cout << "Please enter a new name(FIRSTNAME ONLY, NO SPACES): ";
										std::cin >> info;
										std::cout << "\n";
										C1.setN(info);
										std::cout << "Name updated!\n";
										L1.write("CLERK " + C1.getName() + "changed their name");
									}
									pOP = -1;
									info = "";
									break;
								case 2: // VIEW PROFILE
									L1.write("CLERK " + C1.getName() + "requested their work profile be displayed");
									C1.printClerkProfile();
									L1.write("SYSTEM printed worker profile to screen");
									break;
								case 3: // LOGOUT
									std::cout << "Good-Bye!\n";
									L1.write("CLERK " + C1.getName() + "logged out");
									break;
							}
						}
						break;
					case 2:		// MANAGER LOGIN
						L1.write("MANAGER " + M1.getName() + "logged in");
						while(manOP != 5){
                                                        std::cout << "Please select an option: \n";
                                                        std::cout << "1. List Orders\n";
                                                        std::cout << "2. View Inventory\n";
							std::cout << "3. View Personal Profile\n";
							std::cout << "4. View Workers Profile\n";
							std::cout << "5. Logout\n";
                                                        std::cout << "Enter your selection: ";
                                                        std::cin >> manOP;
                                                        std::cout << "\n";

                                                        switch(manOP){
                                                                case 1: // Print all orders
									L1.write("MANAGER " + M1.getName() + "requested all orders be printed");
									std::cout << "Total order(s) in the system: " << O.numOrders();
                                                                        std::cout << "\n";
                                                                        O.printOrders();
                                                                        std::cout << "\n";
									L1.write("SYSTEM printed all orders to screen");
                                                                        break;
                                                                case 2: // Display Inventory
									L1.write("MANAGER " + M1.getName() + "requested their inventory be displayed");
                                                                        INV.printMaterials();
                                                                        std::cout << "\n";
                                                                        INV.printItems();
                                                                        std::cout << "\n";
									L1.write("SYSTEM printed manager inventory to screen");
                                                                        break;
								case 3: // Display personal profile
									L1.write("MANAGER " + M1.getName() + "requested their manager profile be displayed");
									std::cout << "\n";
									M1.printManagerProfile();
									std::cout << "\n";
									L1.write("SYSTEM displayed managers profile to screen");
									break;
								case 4: // Display workers profile
									L1.write("MANAGER " + M1.getName() + "requested their employees profile be displayed");
									std::cout << "\n";
									C1.printClerkProfile();	
									std::cout << "\n";
									L1.write("SYSTEM printed workers profile to screen");
									break;
                                                                case 5:
                                                                        std::cout << "Good-Bye!\n";
									L1.write("MANAGER " + M1.getName() + "logged out");
                                                                        break;
                                                        }
						}
						break;
					case 3:		// SALES LOGIN
						L1.write("ANALIST " + A1.getName() + "logged in");
						while(saleOP != 3){
							std::cout << "Please select an option: \n";
							std::cout << "1. List Users\n";
							std::cout << "2. View All User Profiles\n";
							std::cout << "3. Logout\n";
							std::cout << "Enter your selection: ";
							std::cin >> saleOP;
							std::cout << "\n";
	
							switch(saleOP){
								case 1: //Print all users
									L1.write("ANALIST " + A1.getName() + "requested a list of all users");
									std::cout << "\n";
									U1.printUsers();
									std::cout << "\n";
									L1.write("SYSTEM displayed all users to screen");
									break;								
								case 2: //Print all user profiles
									L1.write("ANALIST " + A1.getName() + "requested all users profiles");
									CC1.printCustomerProfile();
									std::cout << "\n";
									C1.printClerkProfile();
									std::cout << "\n";
									M1.printManagerProfile();
									std::cout << "\n";
									L1.write("SYSTEM displayed all manager, worker, and customer profiles");
									break;							
								case 3:
									std::cout << "Good-Bye!\n";
									L1.write("ANALIST " + A1.getName() + "logged out");
									break;
							}
						}
						break;
					default:
						std::cout << "ERROR: user type does not exist!\n";
						break;
				}		
				break;
			default:	// DO nothing, this should never happen, loggedIn must be set to true to exit loop
				loggedIn = true;
				break;
			}
		}		
	}
}
