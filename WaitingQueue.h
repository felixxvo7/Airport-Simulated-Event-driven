//-----------------------------------------
// CLASS: WaitingQueue
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a waiting queue for events.
//          Prioritizes landing events over takeoff events.
//-----------------------------------------
#pragma once
#include "Queue.h"

class WaitingQueue : public Queue {
public:
    void enqueue(Event* event) override;
    Event* dequeue() override;
};