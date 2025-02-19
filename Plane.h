#pragma once
#include <iostream>
using namespace std;

class Plane{
    private:
        static int nextAtcID;
        int atcID;
        string callSign;
        int flightNumber;
        string size;

    public:
        Plane(string callSign, int flightNumber, string size);
        
        // Returns time based on size and request type
        int getTimeRequired();
        int getAtcID();
        string getInfo();
};