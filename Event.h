// Event.h
//-----------------------------------------
// CLASS: Event
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Abstract base class for simulation events.
//          Handles common event properties and interface
//          for polymorphic event processing.
//-----------------------------------------

#pragma once
#include <iostream>
class Plane;
class Runway;
using namespace std;

class Event {
    protected:
        const int FINAL_APPROACH_TIME = 2;
        const int RUNWAY_TIME = 1; 
        int time;
        Plane* plane;
    public:
        Event();
        Event(int t, Plane* plane);
        virtual ~Event();

        // Instance methods
        int getTime();
        string getPlaneInfo();
        int getRequireTime();
        int getAtcID();
        Plane* getPlane();
        
        // Pure virtual methods for derived classes to implement
        virtual Event* process(Runway* R,int currentTime) = 0;
        virtual bool isLanding() { return false; }
        virtual string getType() = 0;
        virtual void print();
};