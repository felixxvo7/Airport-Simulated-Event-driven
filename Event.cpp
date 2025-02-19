#pragma once
#include "Event.h"


// Constructor definition
Event::Event(int t, Plane* plane) : time(t), plane(plane){}

// Virtual destructor definition
Event::~Event() {}

// Accessor method to get the event time
int Event::getTime() {
    return time;
}

// Accessor method to get the ATC ID
Plane* Event::getPlane() {
    return plane;
}

int Event::getAtcID(){
    return plane->getAtcID();
}

// Virtual print method definition for debugging purposes
void Event::print() {
    std::cout << "Event: Time = " << time << ", ATC ID = " << plane->getAtcID() << std::endl;
}
