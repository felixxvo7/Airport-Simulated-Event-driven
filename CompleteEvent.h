// CompleteEvent.h
#pragma once
#include "Event.h"

class CompleteEvent : public Event {
public:
    CompleteEvent(int t, Plane* p);
    void process() override;
    void print() override;
    bool isComplete() override { return true; }
};