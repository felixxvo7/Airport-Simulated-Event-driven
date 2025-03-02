// RequestTakeoffEvent.h
//-----------------------------------------
// CLASS: RequestTakeoffEvent
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a request for takeoff event in the simulation.
//-----------------------------------------

#pragma once
#include "Event.h"

class RequestTakeoffEvent : public Event {
public:
    // Default constructor
    RequestTakeoffEvent();
    RequestTakeoffEvent(int t, Plane* p); // Constructor

    // Process the takeoff request event
    Event* process(Runway* R, int currentTime) override;

    // Print event details
    void print() override;

    // Get the event type
    string getType() override;
};