#include "PriorityQueue.h"

#include <iostream>

int main() {
    PriorityQueue pq;

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(5);

    std::cout << "PriorityQueue: ";
    pq.display(); // Output: 5 10 20 30

    std::cout << "Dequeue: " << pq.dequeue() << std::endl; // Output: 5
    std::cout << "Dequeue: " << pq.dequeue() << std::endl; // Output: 10

    std::cout << "PriorityQueue after dequeue: ";
    pq.display(); // Output: 20 30

    return 0;
}