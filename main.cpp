// main.cpp
//-----------------------------------------
// NAME: Felix Vo
// STUDENT NUMBER: 7924848
// COURSE: COMP 2150
// INSTRUCTOR: Heather Matheson
// ASSIGNMENT: Assignment 2
// QUESTION: Question 1
// 
// REMARKS: Airport runway simulation program that models
//          aircraft landing/takeoff operations and calculates
//          total waiting time inefficiencies.
//-----------------------------------------
#include "Simulation.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {

	if(argc != 3)
	{
		cout<<"USAGE: FileReadingExample.exe filename numRunways"<<endl;
		cout<<"where numRunways is an integer > 0."<<endl;
		return 0;
	}

	string filename = argv[1];
	int numRunways = stoi(argv[2]);
    if (numRunways < 1) {
        std::cerr << "Error: Number of runways must be ≥ 1\n";
        return EXIT_FAILURE;
    }
    cout << "The filename is: " << filename << endl;
	cout << "The number of runways is: " << numRunways <<endl;

    try {
        // Create and run simulation
        Simulation simulation(filename, numRunways);
        simulation.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}