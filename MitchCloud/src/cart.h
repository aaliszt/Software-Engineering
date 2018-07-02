//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: cart.h
//Create Date: Nov, 9 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef CART
#define CART

#include <vector>
#include "item.h"

class cart{
public:
	cart(){ totalCost = 0; }
	double getTotal();				// Get cart totalCost
	void getItems();				// Print out items in cart
	void addItem(item i) { cartItems.push_back(i); }// Add item to cart
	void emptyCart(){ cartItems.clear(); }		// Clear the carts contents
	void removeItem(item i);			// remove an item from the cart (removes duplicates as well)
private:
	std::vector<item> cartItems;			// vector of items in cart
	double totalCost;				// cost of cart
};

#endif
