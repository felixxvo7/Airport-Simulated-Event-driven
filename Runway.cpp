#include "Runway.h"

Runway::Runway(int runwayId) : id(runwayId), nextAvailableTime(0) {}

bool Runway::isAvailable(int currentTime) {
    return currentTime >= nextAvailableTime;
}

int Runway::assign(int currentTime,Plane* plane, bool isLanding) {
    int turbulence = plane->getTimeRequired();
    int operationTime = 0;
    
    if (isLanding) {
        // Landing: 2m approach + 1m runway + turbulence
        operationTime = 2 + 1 + turbulence;
    } else {
        // Takeoff: 1m runway + turbulence
        operationTime = 1 + turbulence;
    }
    
    nextAvailableTime = currentTime + operationTime;
    return operationTime;
}

int Runway::getId() {
    return id;
}
int Runway::getNextAvailableTime() {
    return nextAvailableTime;
}