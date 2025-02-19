// TakeoffEvent.h
#pragma once
#include "Event.h"

class TakeoffEvent : public Event {
public:
    TakeoffEvent(int t, Plane* p);
    void process() override;
    void print() override;
};