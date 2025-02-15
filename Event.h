#pragma once
class Plane;
class Event 
{
    protected:
        int time;
        Event* next;
        Plane& plane_; 
    public:
        //Constructors
        Event(int, Plane&); 

        //Instance methods
        int getTime();
};