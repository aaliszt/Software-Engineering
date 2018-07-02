//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: manager.cpp
//Create Date: Nov, 9 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include "manager.h"
#include <iostream>

void manager::printManagerProfile(){
	std::cout << "--Profile information for " << username << "--\n";
        std::cout << "NAME: " << name << std::endl;
        std::cout << "USERNAME: " << username << std::endl;
        std::cout << "PASSWORD: " << password << std::endl;
        std::cout << "HOURS WORKED: " << hours << std::endl;
}
