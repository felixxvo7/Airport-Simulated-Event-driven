// EventQueue.cpp
#include "PriorityQueue.h"
#include "LandingEvent.h"  // To check event types
#include "TakeoffEvent.h"


// PriorityQueue.cpp - Updated enqueue logic
#include "PriorityQueue.h"
#include "LandingEvent.h"
#include "TakeoffEvent.h"

void PriorityQueue::enqueue(Event* newEvent) {
    Node* newNode = new Node(newEvent);
    int newTime = newEvent->getTime();
    bool newIsComplete = newEvent->isComplete();
    bool newIsLanding = newEvent->isLanding();
    int newAtcID = newEvent->getAtcID();

    // 1. Insert at head if:
    //    - Queue is empty
    //    - New event has higher priority than head
    if (!head || 
        (newTime < head->event->getTime()) ||
        (newTime == head->event->getTime() && newIsComplete && !head->event->isComplete()) ||
        (newTime == head->event->getTime() && newIsComplete == head->event->isComplete() && 
         ((newIsLanding && !head->event->isLanding()) || 
          (newIsLanding == head->event->isLanding() && newAtcID < head->event->getAtcID())))) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // 2. Traverse to find correct position
    Node* current = head;
    while (current->next) {
        Event* currEvent = current->next->event;
        int currTime = currEvent->getTime();
        bool currIsComplete = currEvent->isComplete();
        bool currIsLanding = currEvent->isLanding();
        int currAtcID = currEvent->getAtcID();

        // Break insertion when:
        // - New event has higher priority than next node
        if (newTime < currTime ||
            (newTime == currTime && newIsComplete && !currIsComplete) ||
            (newTime == currTime && newIsComplete == currIsComplete && 
             ((newIsLanding && !currIsLanding) || 
              (newIsLanding == currIsLanding && newAtcID < currAtcID)))) {
            break;
        }
        current = current->next;
    }

    // 3. Insert after current node
    newNode->next = current->next;
    current->next = newNode;
}

Event* PriorityQueue::dequeue() {
    if (!head) return nullptr;
    
    Node* temp = head;
    Event* result = head->event;
    head = head->next;
    delete temp;
    return result;
}
