#include <iostream>
#include "PriorityQueue.h"
#include "LandingEvent.h"
#include "TakeoffEvent.h"
#include "CompleteEvent.h"
#include "Plane.h"

using namespace std;

int main() {
    PriorityQueue priorityQueue;

    // Create test planes (ATC IDs will auto-increment from 1)
    Plane* plane1 = new Plane("Delta", 100, "small");
    Plane* plane2 = new Plane("United", 200, "large");
    Plane* plane3 = new Plane("American", 300, "heavy");
    Plane* plane4 = new Plane("Southwest", 400, "super");
    Plane* plane5 = new Plane("JetBlue", 500, "small");

    // Create test events with different priorities
    Event* events[] = {
        // Time 5 events (should order: Complete > Landing > Takeoff)
        new TakeoffEvent(5, plane4),     // Takeoff, ATC 4
        new LandingEvent(5, plane1),     // Landing, ATC 1
        new CompleteEvent(5, plane3),    // Complete, ATC 3
        new LandingEvent(5, plane5),     // Landing, ATC 5
        new CompleteEvent(5, plane2),    // Complete, ATC 2
        
        // Time 10 events (normal priority)
        new TakeoffEvent(10, plane1),    // Takeoff, ATC 1
        new LandingEvent(10, plane3)      // Landing, ATC 3
    };

    // Enqueue all events in random order
    cout << "===== Enqueuing Events =====\n";
    for (Event* event : events) {
        cout << "Enqueuing: " 
             << (event->isComplete() ? "Complete" : 
                (event->isLanding() ? "Landing" : "Takeoff"))
             << " Event | Time: " << event->getTime()
             << " | ATC ID: " << event->getAtcID() << endl;
        priorityQueue.enqueue(event);
    }

    // Dequeue and process events
    cout << "\n===== Dequeue Order =====" << endl;
    while (!priorityQueue.isEmpty()) {
        Event* currentEvent = priorityQueue.dequeue();
        cout << "Processing: "
             << (currentEvent->isComplete() ? "Complete" : 
                (currentEvent->isLanding() ? "Landing" : "Takeoff"))
             << " Event | Time: " << currentEvent->getTime()
             << " | ATC ID: " << currentEvent->getAtcID() << endl;
        delete currentEvent;
    }

    // Cleanup planes
    delete plane1;
    delete plane2;
    delete plane3;
    delete plane4;
    delete plane5;

    return 0;
}