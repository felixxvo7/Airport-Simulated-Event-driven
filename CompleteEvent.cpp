#include "CompleteEvent.h"
#include <iostream>

CompleteEvent::CompleteEvent(int t, Plane* p) : Event(t, p) {}

void CompleteEvent::process() {
    // Logic to process the complete event
    std::cout << "Processing complete event for plane: " << plane->getAtcID() << " at time: " << time << std::endl;
}

void CompleteEvent::print() {
    // Print details of the complete event
    std::cout << "Complete Event - Time: " << time << ", Plane ID: " << getPlane()->getAtcID() << std::endl;
}