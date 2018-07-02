//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: customer.cpp
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include "customer.h"
#include <iostream>

void customer::printCustomerProfile(){
	std::cout << "--Profile information for " << username << "--\n";
	std::cout << "NAME: " << name << std::endl;
	std::cout << "AGE: " << age << std::endl;
	std::cout << "USERNAME: " << username << std::endl;
	std::cout << "PASSWORD: " << password << std::endl;
	std::cout << "ADDRESS: " << address << std::endl;
	std::cout << "PHONE #: " << phoneNum << std::endl;
	std::cout << "GENDER: " << gender << std::endl;	
}
