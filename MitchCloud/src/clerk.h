//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: clerk.h
//Create Date: Nov, 9 2017
//Author: Aaron Liszt
//Version: 2.0
//------------------------------------------------------------------

#ifndef CLERK 
#define CLERK

#include <string>
#include "cart.h"

class clerk{
public:
	clerk() { username = "default"; password = " "; name = " "; phoneNum = " "; hours = 0;}
	std::string getName() { return username; }	// Return clerks username
	std::string getPass() { return password; }	// return clerks password
	void setName(std::string u) { username = u; }	// set the clerks username to a specified value
	void setPass(std::string p) { password = p; }	// set the clerks password to a specified value
	cart uCart;					// cart containing clerks items
	std::string getN() { return name; }		// return clerks name
	std::string getPhone() { return phoneNum; }	// return clerks phone num
	int getHours() { return hours; }		// return clerks hours
	void setN(std::string n) { name = n; }		// set clerks name
	void setPhone(std::string p) { phoneNum = p; }	// set clerks phone num
	void setHours(int i) { hours = i; }		// set clerks hours
	void printClerkProfile();			// display all information about the clerk to the screen
private:
	std::string username;				// clerks username
	std::string password;				// clerks password
	std::string name;				// clerks name
	std::string phoneNum;				// clerks phone number
	int hours;					// clerks hours worked
};

#endif
