//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: logger.cpp
//Create Date: Nov 10, 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#include <stdio.h>
#include <time.h>
#include <string>
#include "logger.h"


// Default constructor for logger
// Gets the current time from system and convert it to a formatted string
logger::logger(){
	time_t rawtime;   	// raw time info
     	struct tm * timeInfo;	// structured timeInfo   
	time(&rawtime);		// get current time in rawtime format
	timeInfo = localtime(&rawtime);	// get structured time from rawtime

	char formatTime [50];
     	strftime(formatTime, 50, "logs/log_%m-%d-%Y_%I-%M-%S-%p.txt", timeInfo); // Format timeInfo and store it in formatTime
	
	std::string f(formatTime); // Construct formatTime into a string
	filename = f;
}

// write information to log file
void logger::write(std::string s){
	std::ofstream logFile;	
	logFile.open(filename, std::ofstream::app); // Open/create log file with compiled filename and write to end of file
	logFile << s << "\n";
	logFile.close();
}
