#include "Node.h"

//Initializes a new Node with the given Event.
Node::Node(Event* e) : event(e), next(nullptr) {}