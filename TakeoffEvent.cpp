// TakeoffEvent.cpp
#include "TakeoffEvent.h"
#include <iostream>

TakeoffEvent::TakeoffEvent(int t, Plane* p) : Event(t, p) {}

void TakeoffEvent::process() {
    // Basic implementation for testing
    std::cout << "TAKEOFF PROCESSED: ";
    print();
}

void TakeoffEvent::print() {
    std::cout << "[TAKEOFF] Time: " << getTime() 
              << " | Plane: " << getPlane()->getInfo() << "\n";
}