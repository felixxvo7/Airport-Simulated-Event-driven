//-----------------------------------------
// CLASS: PriorityQueue
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a priority queue for events.
//          Events are ordered by time and type (landing before takeoff).
//-----------------------------------------
#pragma once
#include "Queue.h"

class PriorityQueue : public Queue {
public:
    void enqueue(Event* event) override;
    Event* dequeue() override;
};