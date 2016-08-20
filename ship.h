#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include "grid.h"
using namespace std;

class Ship
{
    protected:
        int size;
        // list <Location> placement; 
    public:
        Ship() {size = 0;};
        void SetSize(int size);
        int GetSize();
        // list<Location> getPlacement();
        Location setPoint(int uX, int uY);
        Location VcreateNextPoint(int uX, int uY);
        Location HcreateNextPoint(int uX, int uY);
        // void printPlacement();
};

// void Ship::printPlacement()
// {
//       for (list<Location>::iterator i = getPlacement().begin(); i != getPlacement().end(); i++)
//     {
//         // Location A = *i;
//         // A.displayLocation();
//         // *i.displayLocation();
//         Location B = *i;
//         cout << B;
//     }    
// }

void Ship::SetSize(int size)
{
    this->size = size; 
}

int Ship::GetSize()
{
    return size;
}

// list<Location> Ship::getPlacement()
// {
//     return placement;
// }

Location Ship::setPoint (int uX, int uY)
{
    Location A;
    A.setX(uX);
    A.setY(uY);
    return A;
}

Location Ship::VcreateNextPoint(int uX, int uY)
{
    int point = uX;
    Location B;
    // for (int i = 1; i < size; i++)
    // {
    if (point >= 9)
    {
        point = 9-size;   
    }
    B.setX(point + 1);
    B.setY(uY);
    point += 1;
    //}
    return B;
}

Location Ship::HcreateNextPoint(int uX, int uY)
{
    int point = uY;
    Location B;
    // for (int i = 1; i < size; i++)
    // {
    if (point == 9)
    {
        point = 9-size;   
    }
    B.setY(point + 1);
    B.setX(uX);
    point += 1;
    //}
    return B;
}

class Size2Ship : public Ship 
{
    protected:
        Location point1;
        Location point2;
    public:
        Size2Ship() {SetSize(2);};
        void Size2ShipPrint();
};

void Size2Ship::Size2ShipPrint()
{
    cout << "POINTS!: " << endl;
    cout << "Point 1: " << point1.getX() << " " << point1.getY() << endl;
    cout << "Point 2: " << point2.getX() << " " << point2.getY() << endl;
}

class VSize2Ship : public Size2Ship
{
    public:
        VSize2Ship();
};

VSize2Ship::VSize2Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = VcreateNextPoint(uX, uY);
}

class HSize2Ship : public Size2Ship
{
    public:
        HSize2Ship();
};

HSize2Ship::HSize2Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = HcreateNextPoint(uX,uY);
}

class Size3Ship : public Ship 
{
    protected:
        Location point1;
        Location point2;
        Location point3;
    public:
        Size3Ship() {SetSize(3);};
        void Size3ShipPrint();
};

void Size3Ship::Size3ShipPrint()
{
    cout << "POINTS!: " << endl;
    cout << "Point 1: " << point1.getX() << " " << point1.getY() << endl;
    cout << "Point 2: " << point2.getX() << " " << point2.getY() << endl;
    cout << "Point 3: " << point3.getX() << " " << point3.getY() << endl;
}

class VSize3Ship : public Size3Ship
{
    public:
        VSize3Ship();
};

VSize3Ship::VSize3Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = VcreateNextPoint(uX, uY);
    point3 = VcreateNextPoint(point2.getX(),uY);
}

class HSize3Ship : public Size3Ship
{
    public:
        HSize3Ship();   
};

HSize3Ship::HSize3Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = HcreateNextPoint(uX,uY);
    point3 = HcreateNextPoint(uX, point2.getY());
}

class Size4Ship : public Ship 
{
    protected:
        Location point1;
        Location point2;
        Location point3;
        Location point4;
    public:
        Size4Ship() {SetSize(4);};
        void Size4ShipPrint();
};

void Size4Ship::Size4ShipPrint()
{
    cout << "POINTS!: " << endl;
    cout << "Point 1: " << point1.getX() << " " << point1.getY() << endl;
    cout << "Point 2: " << point2.getX() << " " << point2.getY() << endl;
    cout << "Point 3: " << point3.getX() << " " << point3.getY() << endl;
    cout << "Point 4: " << point4.getX() << " " << point4.getY() << endl;
}

class VSize4Ship : public Size4Ship
{
    public:
        VSize4Ship();    
};

VSize4Ship::VSize4Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = VcreateNextPoint(uX, uY);
    point3 = VcreateNextPoint(point2.getX(), uY);
    point4 = VcreateNextPoint(point3.getX(), uY);
}

class HSize4Ship : public Size4Ship
{
    public:
        HSize4Ship();
};

HSize4Ship::HSize4Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = HcreateNextPoint(uX, uY);
    point3 = HcreateNextPoint(uX, point2.getY());
    point4 = HcreateNextPoint(uX, point3.getY());
}

class Size5Ship : public Ship
{
    protected:
        Location point1;
        Location point2;
        Location point3;
        Location point4;
        Location point5;
    public:
        Size5Ship() {SetSize(5);};
        void Size5ShipPrint();

};

void Size5Ship::Size5ShipPrint()
{
    cout << "POINTS!: " << endl;
    cout << "Point 1: " << point1.getX() << " " << point1.getY() << endl;
    cout << "Point 2: " << point2.getX() << " " << point2.getY() << endl;
    cout << "Point 3: " << point3.getX() << " " << point3.getY() << endl;
    cout << "Point 4: " << point4.getX() << " " << point4.getY() << endl;
    cout << "Point 5: " << point5.getX() << " " << point5.getY() << endl;
}

class VSize5Ship : public Size5Ship
{
    public:
        VSize5Ship();
};

VSize5Ship::VSize5Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = VcreateNextPoint(uX, uY);
    point3 = VcreateNextPoint(point2.getX(), uY);
    point4 = VcreateNextPoint(point3.getX(), uY);
    point5 = VcreateNextPoint(point4.getX(), uY);
}

class HSize5Ship : public Size5Ship
{
    public:
        HSize5Ship();
};

HSize5Ship::HSize5Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    point1 = setPoint(uX,uY);
    point2 = HcreateNextPoint(uX, uY);
    point3 = HcreateNextPoint(uX, point2.getY());
    point4 = HcreateNextPoint(uX, point3.getY());
    point5 = HcreateNextPoint(uX, point4.getY());
}