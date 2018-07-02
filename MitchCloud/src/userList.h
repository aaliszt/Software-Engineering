//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: userList.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef USERLIST
#define USERLIST

#include <string>
#include <vector>

class userList{
public:
        userList() { }
        void addUser(std::string uname) { users.push_back(uname); } // Add username to end of user list
	void printUsers();					    // print out all usernames in users
	std::string getUser(int i) { return users[i]; }		    // return the username of a user at a specified index
private:
        std::vector<std::string> users;				    // list of all usernames of all users in the system
};

#endif

