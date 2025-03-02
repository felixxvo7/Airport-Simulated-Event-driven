Airport Runway Simulation

Overview
This program simulates the operations of an airport runway, managing aircraft landing and takeoff requests. It processes events in an event-driven manner, prioritizing landing requests over takeoff requests. The simulation calculates the total time wasted due to unavailability of runways.

Compilation Instructions:

	clang++ *.cpp -std=c++11 -o airport_simulation

	./airport_simulation <filename> <numRunways>

Example:

	./airport_simulation test.txt 1


Author
Felix Vo
Student Number: 7924848
Course: COMP 2150
Instructor: Heather Matheson