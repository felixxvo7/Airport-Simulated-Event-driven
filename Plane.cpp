#include "Plane.h"
#include <iostream>
#include <string>

// Initialize static ATC ID
int Plane::nextAtcID = 1;

// Constructor definition
Plane::Plane( string callSign, int flightNumber, string size)
: callSign(callSign), flightNumber(flightNumber), size(size) {
    atcID = nextAtcID++;
}

// Calculate time required based on size (for landing or takeoff)
int Plane::getTimeRequired() {
    if (size == "small") return 0;
    if (size == "large") return 1;
    if (size == "heavy") return 2;
    if (size == "super") return 3;
    return -1; // Invalid size
}

int Plane::getAtcID() 
{
    return atcID;
}

std::string Plane::getInfo() 
{
    return callSign + " " + to_string(flightNumber)+ " (" + to_string(atcID) + ")" +" " + size;
}