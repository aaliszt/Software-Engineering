//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: item.h
//Create Date: Nov 9, 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef ITEM
#define ITEM

#include <string>

class item{
public:
	item(){ name = "default"; cost = 1; }
	std::string getItemName() { return name; }	// Return the items name
	double getItemCost(){ return cost; }		// return an items cost
	void setItemName(std::string n){ name = n; }	// set the name of an item to a specific value
	void setItemCost(double c){ cost = c; }		// set the cost of an item to a specific value
	void setID(std::string i) { itemID = i; }	// set the itemID of an item
	std::string getID() { return itemID; }		// reutrn the itemID of an item
private:
	std::string name;				// items name
	std::string itemID;				// items ID
	double cost;					// cost of item
};

#endif
