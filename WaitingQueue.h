// WaitingQueue.h
#pragma once
#include "Queue.h"

class WaitingQueue : public Queue {
public:
    void enqueue(Event* event) override;
    Event* dequeue() override;
};