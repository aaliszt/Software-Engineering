//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: manager.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef MANAGER
#define MANAGER

#include <string>

class manager{
public:
        manager() { username = "default"; password = " "; name = " "; hours = 0;}
        std::string getName() { return username; }      // Return managers username
        std::string getPass() { return password; }      // return managers password
        void setName(std::string u) { username = u; }   // set the managers username to a specified value
        void setPass(std::string p) { password = p; }   // set the managers password to a specified value
        std::string getN() { return name; }             // return managers name
        int getHours() { return hours; }                // return managers hours
        void setN(std::string n) { name = n; }          // set managers name
        void setHours(int i) { hours = i; }             // set managers hours
        void printManagerProfile();                     // display all information about the managers to the screen
private:
        std::string username;                           // managers username
        std::string password;                           // managers password
        std::string name;                               // managers name
        int hours;                                      // managers hours worked
};

#endif

