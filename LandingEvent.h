#pragma once
#include "Event.h"

class LandingEvent : public Event {
public:
    LandingEvent(int t, Plane* p);
    bool isLanding() override { return true; }
    void process() override;
    void print() override;
};