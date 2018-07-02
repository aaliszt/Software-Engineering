//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: inventory.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef INVENTORY
#define INVENTORY

#include <string>
#include <vector>
#include "menu.h"
#include "item.h"

class inventory{
public:
        inventory() { }
        void printMaterials();		//Print all raw materials with amounts
	void printItems();		//Print all items with amounts
	void addMaterial(std::string m) { materials.push_back(m); }
	void setMaterialAMT(int a) { numMaterial.push_back(a); }
	void addItem(item I) { invItems.push_back(I); }
	void setItemAMT(int i) { numItems.push_back(i); }
private:
	std::vector<std::string> materials;	// list of raw materials
	std::vector<int> numMaterial;		// amount of each raw material (index's match index's in materials)
	std::vector<item> invItems;		// list of inventory items
	std::vector<int> numItems;		// amount of each inventory item (index's match index's in invItems)
};

#endif

