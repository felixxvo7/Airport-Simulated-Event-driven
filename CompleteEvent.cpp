#include "CompleteEvent.h"
#include "Runway.h"
#include <iostream>
using namespace std;

// Default constructor
CompleteEvent::CompleteEvent() {}

// Parameterized constructor
CompleteEvent::CompleteEvent(int t, Plane* p) : Event(t, p) {}

// Process the complete event
Event* CompleteEvent::process(Runway* R, int currentTime) {
    print();
    cout << R->getId() << "." << endl;
    R->release(); // Release the runway
    return nullptr; // No new event is created
}

// Print complete event details
void CompleteEvent::print() {
    Event::print();
    cout << " has cleared the runway ";
}

// Get the event type
string CompleteEvent::getType() {
    return "COMPLETE";
}

// Get the assigned runway
Runway* CompleteEvent::getRunway() {
    return assignedRunway;
}

// Assign a runway to the event
void CompleteEvent::assignRunway(Runway* R) {
    this->assignedRunway = R;
}