//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: userList.cpp
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include "userList.h"
#include <iostream>

// Print out all usernames in users
void userList::printUsers(){
	for(int i = 0; i < users.size(); ++i)
		std::cout << users[i] << "\n";	
}

