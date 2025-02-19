#include "Queue.h"

Queue::~Queue() {
    // Clean up all nodes in the queue
    while (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp->event; // Delete the Event object
        delete temp;        // Delete the Node
    }
}