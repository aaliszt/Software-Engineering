//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: logger.h
//Create Date: Nov 10, 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef LOGGER
#define LOGGER

#include <fstream>

class logger{
private:
	std::string filename;
public:
	logger();
    	//void setFilename();
	void write(std::string);
};		

#endif
