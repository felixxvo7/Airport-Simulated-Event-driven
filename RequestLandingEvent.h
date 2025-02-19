// CompleteEvent.h
#pragma once
#include "Event.h"

class RequestLandingEvent : public Event {
public:
RequestLandingEvent(int t, Plane* p);
    void process() override;
    void print() override;
    bool isLanding() override { return true; } // Implementing the pure virtual function
};