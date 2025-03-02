#include "Event.h"
#include "Plane.h"
#include <iostream>
using namespace std;

// Constructor definition
Event::Event(){}
Event::Event(int t, Plane* plane) : time(t), plane(plane){}

// Virtual destructor definition
Event::~Event() {}

// Accessor method to get the event time
int Event::getTime() {
    return time;
}

// Returns information about the plane
string Event::getPlaneInfo() {
    return plane->getInfo();
}

// Accessor method to get the ATC ID
int Event::getAtcID(){
    return plane->getAtcID();
}

// Returns the associated Plane object
Plane* Event::getPlane(){
    return plane;
}

// Returns the time required for the event
int Event::getRequireTime(){
    return plane->getTimeRequired();
}

// Virtual print method definition for debugging purposes
void Event::print() {
    cout << "TIME: "<< time << "->" << plane->getInfo();
}
