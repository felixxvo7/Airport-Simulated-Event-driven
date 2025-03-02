#include "RequestLandingEvent.h"
#include "LandingEvent.h"
#include "Plane.h"
#include <iostream>
using namespace std;

// Default constructor
RequestLandingEvent::RequestLandingEvent() {}

// Parameterized constructor
RequestLandingEvent::RequestLandingEvent(int t, Plane* p) : Event(t, p) {}


//-----------------------------------------
// Process the Request Landing event
// Assign runway for landing and creates a start event.
// 
// PARAMETERS:
//   Runway* R - Pointer to the assigned runway.
//   int currentTime - The current time in the simulation.
// 
// RETURNS:
//   Event* - Pointer to the newly created StartEvent.
//-----------------------------------------
Event* RequestLandingEvent::process(Runway* R, int currentTime) {
    LandingEvent* landing = new LandingEvent(currentTime, plane);
    landing->assignRunway(R);
    return landing; 
}

// Print landing request event details
void RequestLandingEvent::print() {
    Event::print();
    cout << " inbound for landing." << endl;
}

// Get the event type
string RequestLandingEvent::getType() {
    return "REQUEST";
}

// Check if the event is a landing
bool RequestLandingEvent::isLanding() {
    return true;
}