
//-----------------------------------------
// CLASS: Simulation
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Core class for managing airport runway simulations.
//          Coordinates event processing, runway allocation, and statistics tracking.
//-----------------------------------------
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Runway.h"
#include "Plane.h"
#include "Event.h"
#include "TakeoffEvent.h"
#include "LandingEvent.h"
#include "RequestLandingEvent.h"
#include "RequestTakeoffEvent.h"
#include "CompleteEvent.h"
#include "PriorityQueue.h"
#include "WaitingQueue.h"

using namespace std;

class Simulation
{
    private:
        PriorityQueue eventQueue; 
        WaitingQueue waitingLine;
        Runway* runways; 
        int numRunways;
        
        int nextAtcId;
        int totalWastedTime;
        int currentTime;
        ifstream inputFile;

        void processRequestEvent(Event* event);
        void processStartEvent(Event* event);
        void processCompleteEvent(Event* event);

    public:
    Simulation();
    Simulation(string& filename, int numRunways);

    ~Simulation();

    bool readLine();
    void run();

};