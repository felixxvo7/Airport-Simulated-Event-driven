//-----------------------------------------
// CLASS: Plane
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a plane with an ID and status (landed or in-flight).
//-----------------------------------------

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Plane{
    private:
        static int nextAtcID;
        int atcID;
        string callSign;
        int flightNumber;
        string size;

    public:
    // Constructor to initialize the plane
    Plane(std::string callSign, int flightNumber, std::string size);

    // Returns time based on size and request type
    int getTimeRequired();

    // Get the ATC ID
    int getAtcID();

    // Get information about the plane
    std::string getInfo();
};