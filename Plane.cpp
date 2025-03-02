#include "Plane.h"

// Initialize static ATC ID
int Plane::nextAtcID = 1;

// Constructor definition
Plane::Plane(std::string callSign, int flightNumber, std::string size)
    : callSign(callSign), flightNumber(flightNumber), size(size) {
    atcID = nextAtcID++; // Assign the next ATC ID
}

// Calculate time required based on size (for landing or takeoff)
int Plane::getTimeRequired() {
    if (size == "small") return 0;
    if (size == "large") return 1;
    if (size == "heavy") return 2;
    if (size == "super") return 3;
    return -1; // Invalid size
}

// Get the ATC ID
int Plane::getAtcID() {
    return atcID;
}

// Get information about the plane
std::string Plane::getInfo() {
    return callSign + " " + to_string(flightNumber) + " (" + to_string(atcID) + ")" + " " + size;
}