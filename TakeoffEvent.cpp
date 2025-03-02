// TakeoffEvent.cpp
#include "TakeoffEvent.h"
#include "CompleteEvent.h"
#include "Runway.h"
#include <iostream>
using namespace std;

// Default constructor
TakeoffEvent::TakeoffEvent(){}

// Parameterized constructor
TakeoffEvent::TakeoffEvent(int t, Plane* p) : Event(t, p) {}

//-----------------------------------------
// Process the takeoff event
// Calculates the time required for takeoff and creates a complete event.
// 
// PARAMETERS:
//   Runway* R - Pointer to the assigned runway.
//   int currentTime - The current time in the simulation.
// 
// RETURNS:
//   Event* - Pointer to the newly created CompleteEvent.
//-----------------------------------------
Event* TakeoffEvent::process(Runway* R,int currentTime) {
    int timeRequired = RUNWAY_TIME + getRequireTime();
    int endTime = currentTime + timeRequired;

    // Print the details of the takeoff event
    print();
    cout << R->getId() << ". (time req. for takeoff: " <<  timeRequired << ")." << endl;

    CompleteEvent* complete = new CompleteEvent(endTime,plane);

    // Mark the runway as assigned
    complete->assignRunway(R);
    R->assign();

    return complete;
}

// Print takeoff event details
void TakeoffEvent::print() {
    Event::print();
    cout << " cleared for takeoff on runway ";
}

// Get the assigned runway
Runway* TakeoffEvent::getRunway() {
    return assignedRunway;
}

// Assign a runway to the event
void TakeoffEvent::assignRunway(Runway* R) {
    this->assignedRunway = R;
}

// Get the type of the event
string TakeoffEvent::getType() {
    return "START";
}