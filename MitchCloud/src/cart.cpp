//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: cart.cpp
//Create Date: Nov, 9 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "cart.h"

// Print out every item in the cart
void cart::getItems(){
	for(int i = 0; i < cartItems.size(); ++i)
		std::cout << cartItems[i].getItemName() << " $" << cartItems[i].getItemCost() << "\n";	
}

// Return the total cost of all the items in the cart
double cart::getTotal(){
	double total = 0;
	for(int i = 0; i < cartItems.size(); ++i)
                total = total + cartItems[i].getItemCost();

	totalCost = total;	
	if(cartItems.size() == 0)
		totalCost = 0;

	return totalCost;
}

// Remove an item from the cart
// (removes all duplicates of the item as well)
void cart::removeItem(item it){
	 for(int i = 0; i < cartItems.size(); ++i){
                if(it.getItemName() == cartItems[i].getItemName()){
			cartItems.erase(cartItems.begin()+i);
			i = -1;
		}
	}
}
