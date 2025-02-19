#pragma once
#include "Plane.h"

class Runway {
private:
    int id;
    int nextAvailableTime;

public:
    Runway(int runwayId);
    bool isAvailable(int currentTime);
    int getNextAvailableTime();
    int assign(int currentTime, Plane* plane, bool isLanding);
    int getId();
};
