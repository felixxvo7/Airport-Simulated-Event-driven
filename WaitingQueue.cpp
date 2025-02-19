#include "WaitingQueue.h"

// Enqueue method to add an event to the end of the queue
void WaitingQueue::enqueue(Event* event) {
    Node* newNode = new Node(event); // Create a new node for the event

    if (isEmpty()) {
        head = newNode; // If the queue is empty, set head to the new node
    } else {
        Node* current = head;
        // Traverse to the end of the queue
        while (current->next) {
            current = current->next;
        }
        current->next = newNode; // Link the new node at the end
    }
}

// Dequeue method to remove and return the event from the front of the queue
Event* WaitingQueue::dequeue() {
    if (isEmpty()) return nullptr; // Return nullptr if the queue is empty

    Node* temp = head; // Store the current head
    Event* event = head->event; // Get the event from the head
    head = head->next; // Move head to the next node
    delete temp; // Clean up the old head node
    return event; // Return the event
}