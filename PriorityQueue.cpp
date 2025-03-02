

#include "PriorityQueue.h"
#include "CompleteEvent.h"

//-----------------------------------------
// Enqueue: PriorityQueue
//
// PURPOSE: Adds an event to the priority queue, maintaining the order based on time and type.
// 
// PARAMETERS:
//   Event* newEvent - Pointer to the event to be added to the queue.
//-----------------------------------------
void PriorityQueue::enqueue(Event* newEvent) {
    Node* newNode = new Node(newEvent);
    int newTime = newEvent->getTime();
    bool newIsComplete = newEvent->getType() == "COMPLETE";
    bool newIsLanding = newEvent->isLanding();
    int newAtcID = newEvent->getAtcID();


    // This followed by empty -> time -> priority (complete - landing - takeoff) -> ATCID
    if (!head || 
        (newTime < head->event->getTime()) ||
        (newTime == head->event->getTime() && newIsComplete && (head->event->getType() != "COMPLETE")) ||
        (newTime == head->event->getTime() && newIsComplete == (head->event->getType() == "COMPLETE")  && ((newIsLanding && !head->event->isLanding()) || 
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
        bool currIsComplete = currEvent->getType() == "COMPLETE";
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

//-----------------------------------------
// Dequeue: PriorityQueue
//
// PURPOSE: Removes and returns the event from the front of the priority queue.
// 
// RETURNS:
//   Event* - Pointer to the event that was removed from the queue.
//-----------------------------------------
Event* PriorityQueue::dequeue() {
    if (!head) return nullptr;
    
    Node* temp = head;
    Event* result = head->event;
    head = head->next;
    delete temp;
    return result;
}
