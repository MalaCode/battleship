#ifndef Location_H
#define Location_H

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;



class Location
{
    private:
        int x;
        int y;
    public:
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        void displayLocation ();
};

void Location::setX(int x)
{
    this->x = x;
}

int Location::getX()
{
    return this->x;
}

void Location::setY(int y)
{
    this->y = y;
}

int Location::getY()
{
    return this->y;
}

void Location::displayLocation()
{
    cout << getX() << " " << getY();
}

#endif