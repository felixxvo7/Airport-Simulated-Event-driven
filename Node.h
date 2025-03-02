//-----------------------------------------
// CLASS: Node
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a node in a linked list structure for managing 
//          events in the simulation. Each node contains a pointer to 
//          an Event object and a pointer to the next node in the list.
//-----------------------------------------
#pragma once
#include "Event.h"

class Node {
public:
    Event* event; // Pointer to the Event object
    Node* next;   // Pointer to the next Node in the queue

    // Constructor to initialize the Node with an Event
    Node(Event* e);
};