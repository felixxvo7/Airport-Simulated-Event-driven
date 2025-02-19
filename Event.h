#pragma once
#include <iostream>
#include "Plane.h"

class Event 
{
    protected:
        int time;
        Plane* plane;
    public:
        Event(int t, Plane* plane);
        virtual ~Event();

        //Instance methods
        int getTime();
        Plane* getPlane();
        int getAtcID();
        virtual bool isComplete() {return false;}
        
        virtual void process() = 0;
        virtual bool isLanding() {return false;}
        virtual void print();

};