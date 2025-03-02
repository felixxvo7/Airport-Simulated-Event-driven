//-----------------------------------------
// CLASS: Runway
//
// AUTHOR: Felix Vo, 7924848
//
// REMARKS: Represents a runway that can handle landing and takeoff events.
//-----------------------------------------

#pragma once

class Runway {
private:
    int id;
    bool available;

public:
    // Default constructor
    Runway();

    // Parameterized constructor
    Runway(int runwayId);

    // Method to check if the runway is available
    bool isAvailable();

    // Method to get the runway ID
    int getId();

    // Method to assign the runway (set to unavailable)
    void assign();

    // Method to release the runway (set to available)
    void release();
};
