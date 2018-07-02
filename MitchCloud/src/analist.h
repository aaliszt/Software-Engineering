//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: analist.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef ANALIST
#define ANALIST

#include <string>

class analist{
public:
        analist() { username = "default"; password = " "; }
        std::string getName() { return username; }      // return analists username
        std::string getPass() { return password; }      // return analists password
        void setName(std::string u) { username = u; }   // set the analists username to a specified value
        void setPass(std::string p) { password = p; }   // set the analists password to a specified value
private:
        std::string username;                           // analists username
        std::string password;                           // analists password
};

#endif

