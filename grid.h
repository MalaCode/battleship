#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Grid
{
    private:
       char grid [10] [10];
    public:
        void makegrid();
        void printgrid();
        bool pointcheck (int column, int row);
        void hitcheck (int column, int row);
        void choosepoint (int column, int row);
        void createship(int size);
        void placeship ();
        bool pshipcheck (int URH, int UCH, int URT, int UCT, int size);
};

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
        friend ostream & operator<< (ostream &out, const Location &rhs);
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

ostream & operator<< (ostream &out, const Location &rhs)
{
    Location A = rhs;
    out << A.getX() << " " << A.getY() << endl;
    return out;
}