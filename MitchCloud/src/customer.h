//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: customer.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef CUSTOMER
#define CUSTOMER

#include <string>
#include "cart.h"

class customer{
public:
        customer() { username = "default"; password = " "; name = " "; phoneNum = " "; address = " "; gender = ' ';}
        std::string getName() { return username; }      // Return customers username
        std::string getPass() { return password; }      // return customers password
        void setName(std::string u) { username = u; }   // set the customers username to a specified value
        void setPass(std::string p) { password = p; }   // set the customers password to a specified value
        cart cCart;                                     // cart containing customers items
        std::string getN() { return name; }             // return customers name
        std::string getPhone() { return phoneNum; }     // return customers phone num
        std::string getAddress() { return address; }    // return customers address
	char getGender() { return gender; }		// return customers gender
        void setN(std::string n) { name = n; }          // set customers name
        void setPhone(std::string p) { phoneNum = p; }  // set customers phone num
        void setAddress(std::string a) { address = a; } // set customers address
	void setGender(char c) { gender = c; }		// set customers gender
	void printCustomerProfile();			// print out all information on the customer in an organized fashion
	int getAge(){ return age; }			// return customers age
	void setAge(int a) { age = a; }			// set customers age
private:
        std::string username;                           // customers username
        std::string password;                           // customers password
        std::string name;                               // customers name
        std::string phoneNum;                           // customers phone number
        std::string address;                            // customers addres
	char gender;					// customers gender
	int age;					// customers age
};

#endif

