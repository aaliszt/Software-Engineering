//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: orderList.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef ORDERLIST
#define ORDERLIST

#include <string>
#include <vector>
#include "cart.h"
#include "deliveryMethod.h"
#include "order.h"

class orderList{
public:
        orderList() { }
	void addOrder(order o) { orders.push_back(o); }		// Add an order to the list
        void printOrders();					// Print all orders in the system
	int numOrders() { return orders.size(); }		// Return the number of orders in the system
	order getOrder(int i) { return orders[i]; }		// return a specific order by index
private:
        std::vector<order> orders;
};

#endif

