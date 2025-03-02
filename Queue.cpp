#include "Queue.h"

//-----------------------------------------
// Destructor: Queue
//
// PURPOSE: Cleans up all nodes in the queue to prevent memory leaks.
//-----------------------------------------
Queue::~Queue() {
    while (!isEmpty()) {
        Node* temp = head; // Store the current head
        head = head->next; // Move head to the next node
        delete temp->event; // Delete the Event object
        delete temp; // Delete the Node
    }
}