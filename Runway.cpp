#include "Runway.h"

// Default constructor
Runway::Runway() : id(0), available(true) {}

// Parameterized constructor
Runway::Runway(int runwayId) : id(runwayId), available(true) {}

// Check if the runway is available
bool Runway::isAvailable() {
    return available;
}

// Get the runway ID
int Runway::getId() {
    return id;
}

// Assign the runway (set to unavailable)
void Runway::assign() {
    available = false;
}

// Release the runway (set to available)
void Runway::release() {
    available = true;
}