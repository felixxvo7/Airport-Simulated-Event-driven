// LandingEvent.cpp
#include "LandingEvent.h"
#include <iostream>

LandingEvent::LandingEvent(int t, Plane* p) : Event(t, p) {}

void LandingEvent::process() {
    // Basic implementation for testing
    std::cout << "LANDING PROCESSED: ";
    print();
}

void LandingEvent::print() {
    std::cout << "[LANDING] Time: " << getTime() 
              << " | Plane: " << getPlane()->getInfo() << "\n";
}