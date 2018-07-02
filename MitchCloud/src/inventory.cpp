//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: inventory.cpp
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include "inventory.h"
#include <iostream>
#include <iomanip>

void inventory::printMaterials(){
	std::cout << "MATERIAL\t    " << "AMT\n";
	for(int i = 0; i < materials.size(); ++i)
		std::cout << std::setw(20) << std::left << materials[i] << std::setw(6) << std::left << numMaterial[i] <<"\n";
}

void inventory::printItems(){
	std::cout << "ITEM\t\t         AMT\n";
	for(int i = 0; i < invItems.size(); ++i)
                std::cout << std::setw(25) << std::left << invItems[i].getItemName() << std::setw(7) << std::left << numItems[i] <<"\n";
}
