// LandingEvent.cpp
#include "LandingEvent.h"
#include "CompleteEvent.h"
#include "Runway.h"
#include <iostream>
using namespace std;

// Default constructor
LandingEvent::LandingEvent(){}

// Parameterized constructor
LandingEvent::LandingEvent(int t, Plane* p) : Event(t, p) {}

//-----------------------------------------
// Process the landing event
// Calculates the time required for landing and creates a complete event.
// 
// PARAMETERS:
//   Runway* R - Pointer to the assigned runway.
//   int currentTime - The current time in the simulation.
// 
// RETURNS:
//   Event* - Pointer to the newly created CompleteEvent.
//-----------------------------------------
Event* LandingEvent::process(Runway* R,int currentTime) {

    int timeRequired = FINAL_APPROACH_TIME + RUNWAY_TIME + getRequireTime();
    int endTime = currentTime + timeRequired;

    // Print the details of the landing event
    print();
    cout << R->getId() << ". (time req. for landing: " <<  timeRequired << ")."<< endl;

    CompleteEvent* complete = new CompleteEvent(endTime,plane);

    // Mark the runway as assigned
    complete->assignRunway(R);
    R->assign();
    return complete;
}

// Print landing event details
void LandingEvent::print() {
    Event::print();
    cout  << " cleared for landing on runway " ;
}


// Get the assigned runway
Runway* LandingEvent::getRunway() {
    return assignedRunway;
}

// Assign a runway to the event
void LandingEvent::assignRunway(Runway* R) {
    this->assignedRunway = R;
}

// Check if the event is a landing
bool LandingEvent::isLanding() {
    return true;
}

// Get the type of the event
string LandingEvent::getType() {
    return "START";
}