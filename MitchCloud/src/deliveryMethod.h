//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: deliveryMethod.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef DELIVERYMETHOD
#define DELIVERYMETHOD

#include <string>

class deliveryMethod{
public:
        deliveryMethod() { type = " "; address = " "; }
	deliveryMethod(std::string t, std::string a) { type = t; address = a; }
        std::string getType() { return type; }      	// get delivery type
        std::string getAddress() { return address; }    // get delivery address
        void setType(std::string t) { type = t; }       // set delivery type
        void setAddress(std::string a) { address = a; } // set delivery address
private:
        std::string type;                           // delivery type (pick-up or food-truck)
        std::string address;                        // delivery address
};

#endif

