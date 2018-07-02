#------------------------------------------------------------------
#System Name: MitchCloud
#Artifact Name: Makefile
#Create Date: Nov 9, 2017
#Author: Aaron Liszt
#Version: 2.0
#------------------------------------------------------------------

output: mitchCloudmock.o clerk.o item.o cart.o menu.o logger.o customer.o manager.o analist.o userList.o deliveryMethod.o order.o orderList.o inventory.o taxCalculator.o
	g++ mitchCloudmock.o clerk.o item.o cart.o menu.o logger.o customer.o manager.o analist.o userList.o deliveryMethod.o order.o orderList.o inventory.o taxCalculator.o -Wall -std=c++11 -o mitchcloud

mitchCloudmock.o: mitchCloudmock.cpp
	g++ -Wall -std=c++11 -c  -w mitchCloudmock.cpp

clerk.o: clerk.cpp clerk.h
	 g++ -Wall -std=c++11 -c  -w clerk.cpp

item.o: item.cpp item.h
	g++ -Wall -std=c++11 -c -w item.cpp

cart.o: cart.cpp cart.h
	g++ -Wall -std=c++11 -c -w cart.cpp

menu.o: menu.cpp menu.h
	g++ -Wall -std=c++11 -c -w menu.cpp

logger.o: logger.cpp logger.h
	g++ -Wall -std=c++11 -c -w logger.cpp

customer.o: customer.cpp customer.h
	g++ -Wall -std=c++11 -c -w customer.cpp

manager.o: manager.cpp manager.h
	g++ -Wall -std=c++11 -c -w manager.cpp

analist.o: analist.cpp analist.h
	g++ -Wall -std=c++11 -c -w analist.cpp

userList.o: userList.cpp userList.h
	g++ -Wall -std=c++11 -c -w userList.cpp

deliveryMethod.o: deliveryMethod.cpp deliveryMethod.h
	g++ -Wall -std=c++11 -c -w deliveryMethod.cpp

order.o: order.cpp order.h
	g++ -Wall -std=c++11 -c -w order.cpp

orderList.o: orderList.cpp orderList.h
	g++ -Wall -std=c++11 -c -w orderList.cpp

inventory.o: inventory.cpp inventory.h
	g++ -Wall -std=c++11 -c -w inventory.cpp

taxCalculator.o: taxCalculator.cpp taxCalculator.h
	g++ -Wall -std=c++11 -c -w taxCalculator.cpp

clean:
	rm *.o mitchcloud
