#ifndef Ship_H
#define Ship_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include "location.h"
using namespace std;

class Ship
{
    protected:
        int size;
        Location arr[100];
    public:
        bool isinRange(int &uX, int & uY);
        Ship() {size = 100;};
        void SetSize(int size);
        int getSize();
        Location setPoint(int &uX, int &uY);
        Location VcreateNextPoint(int uX, int uY);
        Location HcreateNextPoint(int uX, int uY);
};

bool Ship::isinRange(int &uX, int &uY)
{
    if(uX <= 9 && uX >= 0 && uY <= 9 && uY >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Ship::SetSize(int size)
{
    this->size = size; 
}

int Ship::getSize()
{
    return size;
}

Location Ship::setPoint (int &uX, int &uY)
{
    Location A;
    while (!isinRange(uX, uY))
    {
        cout << "OUT OF RANGE, TRY AGAIN" << endl;
        cin >> uX;
        cin >> uY;
    }
    A.setX(uX);
    A.setY(uY);
    return A;
}

Location Ship::VcreateNextPoint(int uX, int uY)
{
    int point = uX;
    Location B;
    if (point >= 9)
    {
        point = 9-size;   
    }
    B.setX(point + 1);
    B.setY(uY);
    return B;
}

Location Ship::HcreateNextPoint(int uX, int uY)
{
    int point = uY;
    Location B;
    if (point >= 9)
    {
        point = 9-size;   
    }
    B.setY(point + 1);
    B.setX(uX);
    return B;
}

class Size2Ship : public Ship 
{
    protected:
        Location arr [2];
    public:
        Size2Ship() {SetSize(2);};
        void Size2ShipPrint();
        Location s2getPoint(int index);
};

Location Size2Ship::s2getPoint(int index)
{
    Location A;
    A.setX(arr[index].getX());
    A.setY(arr[index].getY());
    return A;
}

void Size2Ship::Size2ShipPrint()
{
    cout << "POINTS!: " << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Point: " << i << ": " << arr[i].getX() << " " << arr[i].getY() << endl;
    }
}

class VSize2Ship : public Size2Ship
{
    public:
        VSize2Ship();
        VSize2Ship(int uX, int uY);
};

VSize2Ship::VSize2Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
}

VSize2Ship::VSize2Ship(int uX, int uY)
{
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
}

class HSize2Ship : public Size2Ship
{
    public:
        HSize2Ship();
        HSize2Ship(int uX, int uY);
};

HSize2Ship::HSize2Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX,uY);
}

HSize2Ship::HSize2Ship(int uX, int uY)
{ 
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX,uY);
}

class Size3Ship : public Ship 
{
    protected:
        Location arr[3];
    public:
        Size3Ship() {SetSize(3);};
        void Size3ShipPrint();
        Location s3getPoint(int index);
};

Location Size3Ship::s3getPoint(int index)
{
    Location A;
    A.setX(arr[index].getX());
    A.setY(arr[index].getY());
    return A;    
}

void Size3Ship::Size3ShipPrint()
{
    cout << "POINTS!: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Point: " << i << ": " << arr[i].getX() << " " << arr[i].getY() << endl;
    }
}

class VSize3Ship : public Size3Ship
{
    public:
        VSize3Ship();
        VSize3Ship(int uX, int uY);
};

VSize3Ship::VSize3Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
    arr[2] = VcreateNextPoint(arr[1].getX(),uY);
}

VSize3Ship::VSize3Ship(int uX, int uY)
{ 
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
    arr[2] = VcreateNextPoint(arr[1].getX(),uY);
}

class HSize3Ship : public Size3Ship
{
    public:
        HSize3Ship();   
        HSize3Ship(int uX, int uY);
};

HSize3Ship::HSize3Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX,uY);
    arr[2] = HcreateNextPoint(uX, arr[1].getY());
}

HSize3Ship::HSize3Ship(int uX, int uY)
{
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX,uY);
    arr[2] = HcreateNextPoint(uX, arr[1].getY());
}

class Size4Ship : public Ship 
{
    protected:
        Location arr [4];
    public:
        Size4Ship() {SetSize(4);};
        void Size4ShipPrint();
        Location s4getPoint(int index);
};

Location Size4Ship::s4getPoint(int index)
{
    Location A;
    A.setX(arr[index].getX());
    A.setY(arr[index].getY());
    return A;
}

void Size4Ship::Size4ShipPrint()
{
    cout << "POINTS!: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Point: " << i << ": " << arr[i].getX() << " " << arr[i].getY() << endl;
    }
}

class VSize4Ship : public Size4Ship
{
    public:
        VSize4Ship();    
        VSize4Ship(int uX, int uY);
};

VSize4Ship::VSize4Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
    arr[2] = VcreateNextPoint(arr[1].getX(), uY);
    arr[3] = VcreateNextPoint(arr[2].getX(), uY);
}

VSize4Ship::VSize4Ship(int uX, int uY)
{
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
    arr[2] = VcreateNextPoint(arr[1].getX(), uY);
    arr[3] = VcreateNextPoint(arr[2].getX(), uY);
}

class HSize4Ship : public Size4Ship
{
    public:
        HSize4Ship();
        HSize4Ship(int uX, int uY);
};

HSize4Ship::HSize4Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX, uY);
    arr[2] = HcreateNextPoint(uX, arr[1].getY());
    arr[3] = HcreateNextPoint(uX, arr[2].getY());
}

HSize4Ship::HSize4Ship(int uX, int uY)
{
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX, uY);
    arr[2] = HcreateNextPoint(uX, arr[1].getY());
    arr[3] = HcreateNextPoint(uX, arr[2].getY());
}

class Size5Ship : public Ship
{
    protected:
        Location arr[5];
    public:
        Size5Ship() {SetSize(5);};
        void Size5ShipPrint();
        Location s5getPoint(int index);
};

Location Size5Ship::s5getPoint(int index)
{
    Location A;
    A.setX(arr[index].getX());
    A.setY(arr[index].getY());
    return A;
}

void Size5Ship::Size5ShipPrint()
{
    cout << "POINTS!: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Point: " << i << ": " << arr[i].getX() << " " << arr[i].getY() << endl;
    }
}

class VSize5Ship : public Size5Ship
{
    public:
        VSize5Ship();
        VSize5Ship(int uX, int uY);
};

VSize5Ship::VSize5Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Verticle Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
    arr[2] = VcreateNextPoint(arr[1].getX(), uY);
    arr[3] = VcreateNextPoint(arr[2].getX(), uY);
    arr[4] = VcreateNextPoint(arr[3].getX(), uY);
}

VSize5Ship::VSize5Ship(int uX, int uY)
{
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = VcreateNextPoint(uX, uY);
    arr[2] = VcreateNextPoint(arr[1].getX(), uY);
    arr[3] = VcreateNextPoint(arr[2].getX(), uY);
    arr[4] = VcreateNextPoint(arr[3].getX(), uY);
}

class HSize5Ship : public Size5Ship
{
    public:
        HSize5Ship();
        HSize5Ship(int uX, int uY);
};

HSize5Ship::HSize5Ship()
{
    int uX = 0;
    int uY = 0;
    cout << "Create Horizontal Ship, Row first then Column (size " <<  size << ")" << endl;
    cin >> uX;
    cin >> uY;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX, uY);
    arr[2] = HcreateNextPoint(uX, arr[1].getY());
    arr[3] = HcreateNextPoint(uX, arr[2].getY());
    arr[4] = HcreateNextPoint(uX, arr[3].getY());
}

HSize5Ship::HSize5Ship(int uX, int uY)
{
    uX = rand() % 10;
    uY = rand() % 10;
    arr[0] = setPoint(uX,uY);
    arr[1] = HcreateNextPoint(uX, uY);
    arr[2] = HcreateNextPoint(uX, arr[1].getY());
    arr[3] = HcreateNextPoint(uX, arr[2].getY());
    arr[4] = HcreateNextPoint(uX, arr[3].getY());
}

#endif