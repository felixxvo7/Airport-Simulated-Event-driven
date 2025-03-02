// Queue.h
//-----------------------------------------
// CLASS: Queue
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Abstract base class for a queue structure.
//          Provides a common interface for enqueueing and dequeueing events.
//-----------------------------------------
#pragma once
#include "Node.h"
#include <iostream>
class Queue {
protected:
    Node* head;

public:
    // Constructor to initialize the queue
    Queue() : head(nullptr) {}
    virtual ~Queue();

    // Pure virtual functions (subclasses must implement)
    virtual void enqueue(Event* event) = 0;
    virtual Event* dequeue() = 0;

    // Common utility function
    bool isEmpty() const { return head == nullptr; }
};