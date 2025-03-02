#include "Simulation.h"

using namespace std;

//--------------------------------------------------------------------------
    // CONSTRUCTOR: Simulation
    // PURPOSE:      Initialize simulation with default values
    //--------------------------------------------------------------------------
Simulation::Simulation(): numRunways(1), totalWastedTime(0){}


//-----------------------------------------
// Destructor: Simulation
//
// PURPOSE: Cleans up resources used by the simulation.
//-----------------------------------------
Simulation::~Simulation() 
{
    // Clean up dynamically allocated memory
    delete[] runways; // Clean up runways
    inputFile.close(); // Close the file
}

//--------------------------------------------------------------------------
// CONSTRUCTOR: Simulation
// PURPOSE:      Initialize simulation with specific parameters
// PARAMETERS:
//   filename   - Path to event data file
//   numRunways - Number of available runways (>=1)
//--------------------------------------------------------------------------
Simulation::Simulation(string &filename, int numRunways) : numRunways(numRunways), totalWastedTime(0)
{
    currentTime = 0;
    runways = new Runway[numRunways];
    for (int i = 0; i < numRunways; ++i) 
    {
        runways[i] = Runway(i + 1); // Initialize runways with IDs starting from 1
    }
    
    inputFile.open(filename);
    if(!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

}

//--------------------------------------------------------------------------
// METHOD: readLine
// PURPOSE: Read and parse one event from input file
// RETURNS: true if event successfully read/enqueued, false otherwise
//--------------------------------------------------------------------------
bool Simulation::readLine() {
    string line;
    if(getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one
	{

		stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		string token;
		int time = 0;
		string callSign = "";
		string flightNum = "";
		string size = "";
		string requestType = "";
		
		sst >> token;  //grabbing the next token (reading time)
		time = stoi(token); //converting time (string format) to an int
		sst >> callSign;  //grabbing the next token (reading call sign)
		sst >> flightNum;  //grabbing the next token (reading flight number)
		sst >> size;  //grabbing the next token (reading plane size)
		sst >> requestType;  //grabbing the next token (reading request type, either landing or takeoff)

        int flightNumber = stoi(flightNum);
		Plane* plane = new Plane(callSign, flightNumber, size);
        Event* event = nullptr;

        if (requestType == "landing") {
            event = new RequestLandingEvent(time, plane);
        } else if (requestType == "takeoff") {
            event = new RequestTakeoffEvent(time, plane);
        }

        if (event) {
            eventQueue.enqueue(event);
            return true; // Successfully read and enqueued an event
        }
	}
    return false;

}


void Simulation::run() {
    // Read the first arrival from file and put it in the event queue
    if (!readLine()) {
        cout << "Failed to read the first line" << endl;
    }

    cout << "Simulation begins..."  << endl;

    // Main loop to process events
    while (!eventQueue.isEmpty()) {
       
        // Dequeue the next event
        Event* event = eventQueue.dequeue();
        currentTime = event->getTime();

        // Process the event based on its type
        if (event->getType() == "REQUEST") {
            processRequestEvent(event);
        } else if (event->getType() == "START") {
            processStartEvent(event);
        } else if (event->getType() == "COMPLETE") {
            processCompleteEvent(event);
        }

        // Clean up the event after processing
        delete(event);
    }

    // Output the simulation summary
    cout << "#######################" << endl;
    cout << "The simulation has ended." << endl;
    cout << "The number of runways was " << numRunways << "." << endl;
    cout << "The total amount of time wasted because runways were not available was " << totalWastedTime << " minutes." << endl;
    cout << "#######################" << endl;
}

//--------------------------------------------------------------------------
// METHOD: processRequestEvent
//
// PURPOSE: Processes a request event for landing or takeoff. 
//          It checks for available runways and either assigns a runway 
//          to the event or adds the event to the waiting queue if no 
//          runways are available.
//
// PARAMETERS:
//   Event* event - Pointer to the event that is being processed. 
//                  This event can be either a landing or takeoff request.
//--------------------------------------------------------------------------
void Simulation::processRequestEvent(Event* event) {
    Runway* availableRunway = nullptr;

    // Check for available runway
    for (int i = 0; i < numRunways; ++i) {
        if (runways[i].isAvailable()) {
            availableRunway = &runways[i];
            break;
        }
    }
    
    if (availableRunway) {
        // If a runway is available, process the event
        event->print();
        Event* newStartEvent = event->process(availableRunway,currentTime);
        totalWastedTime += currentTime - event->getTime();
        eventQueue.enqueue(newStartEvent);
        
       
    } else {
        event->print();
        Event* waitingEvent;
        // If no runway is available, add the event to the waiting queue
        if (event->isLanding()){
            waitingEvent = new RequestLandingEvent(event->getTime(), event->getPlane());
        } else 
        {
            waitingEvent = new RequestTakeoffEvent(event->getTime(), event->getPlane());
        }
        waitingLine.enqueue(waitingEvent);
    }

    readLine();
}

//--------------------------------------------------------------------------
// METHOD: processStartEvent
//
// PURPOSE: Processes the start event for a landing or takeoff. 
//          This method is responsible for assigning a runway to the 
//          event and creating a complete event once the runway is 
//          assigned.
//
// PARAMETERS:
//   Event* event - Pointer to the start event that is being processed. 
//                  This event indicates that a plane is ready to land 
//                  or take off.
//--------------------------------------------------------------------------
void Simulation::processStartEvent(Event* event) 
{
    Runway* assignRunway = nullptr;

    if (event->isLanding())
    {
        LandingEvent* landingEvent = dynamic_cast<LandingEvent*>(event);
        if (landingEvent) {
            assignRunway = landingEvent->getRunway();
        } else {
            std::cerr << "Error: Event is not a LandingEvent." << std::endl;
            return;
        }
    }
    else
    {
        TakeoffEvent* takeoffEvent = dynamic_cast<TakeoffEvent*>(event);
        if (takeoffEvent) {
            assignRunway = takeoffEvent->getRunway();
        } else {
            std::cerr << "Error: Event is not a TakeoffEvent." << std::endl;
            return;
        }
    }

    // Process the event and enqueue the new complete event
    Event* newCompleteEvent = event->process(assignRunway, currentTime);
    eventQueue.enqueue(newCompleteEvent);
   
}

//--------------------------------------------------------------------------
// METHOD: processCompleteEvent
//
// PURPOSE: Processes the complete event for a landing or takeoff. 
//          This method is responsible for releasing the runway that 
//          was assigned to the event and checking if there are any 
//          waiting events that can now be processed.
//
// PARAMETERS:
//   Event* event - Pointer to the complete event that is being processed. 
//                  This event indicates that a plane has completed its 
//                  landing or takeoff and the runway is now available.
//--------------------------------------------------------------------------
void Simulation::processCompleteEvent(Event* event) {
    CompleteEvent* complete = dynamic_cast<CompleteEvent*>(event);
    
    if (!complete) {
        std::cerr << "Error: Not a CompleteEvent." << std::endl;
        return;
    }
    Runway* assignedRunway = complete->getRunway();
    Event* endEvent = complete->process(assignedRunway,currentTime);
    

    // Process waiting events
    if (!waitingLine.isEmpty()) {
        Event* waitingEvent = waitingLine.dequeue();
        if (!waitingEvent) {
            std::cerr << "Error: Dequeued null event." << std::endl;
            return;
        }
        Event* newStartEvent = waitingEvent->process(assignedRunway, currentTime);
        if (newStartEvent) {
            totalWastedTime += currentTime - waitingEvent->getTime();
            eventQueue.enqueue(newStartEvent);
        } else {
            std::cerr << "Error: Failed to create new event." << std::endl;
        }

        delete waitingEvent;
    }
}