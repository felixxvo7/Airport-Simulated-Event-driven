#include "PriorityQueue.h"
#include <iostream>

//Constructor
PriorityQueue::PriorityQueue(): head(nullptr){}

//Destructor
PriorityQueue::~PriorityQueue()
{
    while(!isEmpty())
    {
        dequeue();
    }
}

void PriorityQueue::enqueue (int time)
{
    Event* newNode = new Event(time);
    if(isEmpty() || time < head->getTime())
    {
        newNode->setNext(head);
        head = newNode;
    } else
    {
        Event* current = head;
        while(current->getNext() != nullptr && current->getNext()->getTime() < time)
        {
            current = current->getNext();
        }

        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
}

int PriorityQueue::dequeue(){
    if(isEmpty())
    {
        std::cerr << "Priority Queue is empty!" << std::endl;
        return -1;
    }

    Event*temp = head;
    int data = temp->getTime();
    head = head->getNext();
    delete temp;
    return data;
}

bool PriorityQueue::isEmpty() const {
    return head == nullptr;
}


void PriorityQueue::display() const {
    Event* current = head;
    while (current != nullptr) {
        std::cout << current->getTime() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}