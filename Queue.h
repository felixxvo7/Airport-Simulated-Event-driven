// Queue.h
#pragma once
#include "Event.h"
#include <iostream>
class Queue {
protected:
    struct Node {
        Event* event;
        Node* next;
        Node(Event* e) : event(e), next(nullptr) {}
    };
    Node* head;

public:
    Queue() : head(nullptr) {}
    virtual ~Queue();

    // Pure virtual functions (subclasses must implement)
    virtual void enqueue(Event* event) = 0;
    virtual Event* dequeue() = 0;

    // Common utility function
    bool isEmpty() const { return head == nullptr; }
};