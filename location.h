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
        Location();
        Location(int uX, int uY);
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        void displayLocation ();
};

Location::Location()
{
    x = 0;
    y = 0;
}

Location::Location(int uX, int uY)
{
    x = uX;
    y = uY;
}

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