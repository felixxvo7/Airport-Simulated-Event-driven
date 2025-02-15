#pragma once
#include "Event.h"


class PriorityQueue{
    private:
        struct Node
        {
            Event* event;
            Node* next;
            Node(Event* e): event(e), next(nullptr) {}
        };
        Node* head;

    public:
        PriorityQueue();
        ~PriorityQueue();

        void enqueue(int data);
        int dequeue();
        bool isEmpty() const;
        void display() const;
};