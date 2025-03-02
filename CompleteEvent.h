// CompleteEvent.h
//-----------------------------------------
// CLASS: CompleteEvent
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a complete event in the simulation.
//-----------------------------------------
#pragma once
#include "Event.h"

class CompleteEvent : public Event {
private:
    Runway* assignedRunway;
public:
    // Default constructor
    CompleteEvent();
    CompleteEvent(int t, Plane* p);

    // Process the complete event
    Event* process(Runway* R, int currentTime) override;

    // Print complete event details
    void print() override;

    // Get the event type
    string getType() override;

    // Get the assigned runway
    Runway* getRunway();

    // Assign a runway to the event
    void assignRunway(Runway* R);
};
