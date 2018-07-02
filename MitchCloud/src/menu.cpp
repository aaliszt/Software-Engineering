//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: menu.cpp
//Create Date: Nov 10, 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include "menu.h"
#include "item.h"
#include <iostream>

// Return an item given its itemID
item menu::getMenuItem(std::string ID){
	item error;
	error.setItemName("INVALID ITEM ID");
	for(int i = 0; i < menuItems.size(); ++i){
		if(menuItems[i].getID() == ID)
			return menuItems[i];
	}
	return error;
}

void menu::printMenu(){
	std::cout << "--MENU ITEMS--\n";
	for(int i = 0; i < menuItems.size(); ++i)
		std::cout << i+1 << ". "<< menuItems[i].getItemName() << " $" << menuItems[i].getItemCost() << "\n";	
}
