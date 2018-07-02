//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: orderList.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include "orderList.h"
#include <iostream>

void orderList::printOrders(){
	for(int i = 0; i < orders.size(); ++i){
		std::cout << "\nORDER FROM: " << orders[i].getName();
		std::cout << "\nDELIVERY METHOD: " << orders[i].deliver.getType();
		std::cout << "\nDELIVERY ADDRESS: " << orders[i].deliver.getAddress() << "\n";
		orders[i].contents.getItems();
		std::cout << std::endl;
	}
}
