// LandingEvent.h
//-----------------------------------------
// CLASS: LandingEvent
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a landing event in the simulation.
//-----------------------------------------
#pragma once
#include "Event.h"
class Runway;
class LandingEvent : public Event {
private:
    Runway* assignedRunway;
public:
    // Default constructor
    LandingEvent();
    LandingEvent(int t, Plane* p);

    Runway* getRunway();

    void assignRunway(Runway* R);
    bool isLanding() override;
    Event* process( Runway* R,int currentTime) override;
    void print() override;
    string getType() override;
};