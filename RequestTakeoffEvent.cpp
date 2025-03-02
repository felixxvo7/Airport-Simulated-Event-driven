#include "RequestTakeoffEvent.h"
#include "TakeoffEvent.h"
#include "Plane.h"
#include <iostream>
using namespace std;

// Default constructor
RequestTakeoffEvent::RequestTakeoffEvent() {}

// Parameterized constructor
RequestTakeoffEvent::RequestTakeoffEvent(int t, Plane* p) : Event(t, p) {}

//-----------------------------------------
// Process the Request Takeoff event
// Assign runway for takoff and creates a start event.
// 
// PARAMETERS:
//   Runway* R - Pointer to the assigned runway.
//   int currentTime - The current time in the simulation.
// 
// RETURNS:
//   Event* - Pointer to the newly created StartEvent.
//-----------------------------------------
Event* RequestTakeoffEvent::process(Runway* R,int currentTime) {
    TakeoffEvent* takeoff = new TakeoffEvent(currentTime,plane);
    takeoff->assignRunway(R);
    return takeoff;
}

// Print takeoff request event details
void RequestTakeoffEvent::print() {
    Event::print();
    cout << " ready for takeoff." << endl;
}

// Get the event type
string RequestTakeoffEvent::getType() {
    return "REQUEST";
}