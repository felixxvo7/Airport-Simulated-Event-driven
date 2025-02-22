// PriorityQueue.h
#pragma once
#include "Queue.h"

class PriorityQueue : public Queue {
public:
    void enqueue(Event* event) override;
    Event* dequeue() override;
};