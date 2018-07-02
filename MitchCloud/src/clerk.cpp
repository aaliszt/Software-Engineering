//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: clerk.cpp
//Create Date: Nov 9, 2017
//Author: Aaron Liszt
//Version: 2.0
//------------------------------------------------------------------

#include <iostream>
#include "clerk.h"

void clerk::printClerkProfile(){
	std::cout << "--Profile information for " << username << "--\n";
        std::cout << "NAME: " << name << std::endl;
        std::cout << "USERNAME: " << username << std::endl;
        std::cout << "PASSWORD: " << password << std::endl;
        std::cout << "PHONE #: " << phoneNum << std::endl;
	std::cout << "HOURS WORKED: " << hours << std::endl;
}
