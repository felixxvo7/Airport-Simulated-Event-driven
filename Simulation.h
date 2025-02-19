#pragma once
#include <iostream>
#include "Runway.h"
#include "PriorityQueue.h"
#include <fstream>

using namespace std;

class Simulation
{
    private:
        PriorityQueue eventQueue; 
        Runway* runways; 
        int numRunways;
        int currentTime;
        int nextAtcId;
        int totalWastedTime;
        std::ifstream inputFile;
    public:
    Simulation(const std::string& filename, int numRunways);
    ~Simulation();

    void run();
    void processEvent(Event* event);
    void scheduleNextRequest();
    void assignRunway(Plane* plane, bool isLanding);
    void calculateWastedTime(Plane* plane, int clearanceTime);
};