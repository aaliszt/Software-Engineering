//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: menu.h
//Create Date: Nov 10, 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef MENU
#define MENU

#include <vector>
#include <string>
#include "item.h"

class menu{
public:
	menu(){}
	std::vector<item> menuItems;			     // vector of all menu items
	void addMenuItem(item i) { menuItems.push_back(i); } // Add an item to menuItems
	item getMenuItem(std::string ID);		     // return an item from menuItems given its itemID
	item getMenuItemN(int i) { return menuItems[i]; }     // return an item from the menu given its position in menuItems
	void printMenu();				    // Print every item in the menu
};

#endif
