
// RequestLandingEvent.h
//-----------------------------------------
// CLASS: RequestLandingEvent
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a request for landing event in the simulation.
//-----------------------------------------
#pragma once
#include "Event.h"

class RequestLandingEvent : public Event {
public:
    // Default constructor
    RequestLandingEvent();
    RequestLandingEvent(int t, Plane* p);

    // Process the landing request event
    Event* process(Runway* R, int currentTime) override;

    // Print event details
    void print() override;

    // Check if the event is a landing
    bool isLanding() override;

    // Get the event type
    string getType() override;
};