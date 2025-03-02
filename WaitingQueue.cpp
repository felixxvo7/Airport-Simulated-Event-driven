#include "WaitingQueue.h"

//-----------------------------------------
// Enqueue: WaitingQueue
//
// PURPOSE: Adds an event to the waiting queue.
//          Prioritizes landing events over takeoff events.
// 
// PARAMETERS:
//   Event* event - Pointer to the event to be added to the queue.
//-----------------------------------------
void WaitingQueue::enqueue(Event* event) {
    Node* newNode = new Node(event); // Create a new node for the event

    if (isEmpty()) {
        head = newNode; // If the queue is empty, set head to the new node
    } else {
        Node* current = head;
        Node* previous = nullptr;

        // Traverse the queue to find the correct position
        while (current) {
            // Check if the current event is a landing event
            if (event->isLanding()) {
                // Insert landing event at the front or before the first takeoff event
                if (previous == nullptr) {
                    // Insert at the head
                    newNode->next = head;
                    head = newNode;
                    return;
                } else {
                    // Insert between previous and current
                    previous->next = newNode;
                    newNode->next = current;
                    return;
                }
            }

            previous = current;
            current = current->next;
        }

        previous->next = newNode;
    }
}

//-----------------------------------------
// Dequeue: WaitingQueue
//
// PURPOSE: Removes and returns the event from the front of the waiting queue.
// 
// RETURNS:
//   Event* - Pointer to the event that was removed from the queue.
//-----------------------------------------
Event* WaitingQueue::dequeue() {
    if (!head) return nullptr;
    Node* temp = head;
    Event* event = temp->event;
    head = head->next;
    delete temp; // Delete the node, NOT the event
    return event; // Caller must delete the event
}
