// TakeoffEvent.h
//-----------------------------------------
// CLASS: TakeoffEvent
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a takeoff event in the simulation.
//-----------------------------------------
#pragma once
#include "Event.h"

class TakeoffEvent : public Event {
private:
    Runway* assignedRunway;
public:
    // Default constructor
    TakeoffEvent();
    TakeoffEvent(int t, Plane* p);

    Runway* getRunway();
    void assignRunway(Runway* R);
    Event* process( Runway* R,int currentTime) override;
    void print() override;
    string getType() override;
};