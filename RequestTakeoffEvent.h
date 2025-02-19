#pragma once
#include "Event.h"

class RequestTakeoffEvent : public Event {
public:
    RequestTakeoffEvent(int t, Plane* p); // Constructor
    void process() override;                // Process method
    void print() override;                  // Print method
    bool isLanding() override { return false; } // Indicate this is a takeoff request
};