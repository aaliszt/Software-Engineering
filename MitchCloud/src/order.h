//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: order.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef ORDER
#define ORDER

#include <string>
#include "cart.h"
#include "deliveryMethod.h"

class order{
public:
        order() { username = "default"; }
	order(deliveryMethod d, cart c, std::string u) { deliver = d; contents = c; username = u; }
        std::string getName() { return username; }      // return order username
        void setName(std::string u) { username = u; }   // set username for order
	deliveryMethod deliver;
        cart contents;
private:
	std::string username;
};

#endif

