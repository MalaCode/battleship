#ifndef Grid_H
#define Grid_H
#include "ship.h"
using namespace std;

class Grid
{
    private:
       char grid [10] [10];
    public:
        void makegrid();
        void printgrid();
        void createship(Ship ship);
        void changePoint(Location A, char mark);
        void checkandchangePoint(Grid &A, Location choice);
        char checkPoint (Location choice);
        bool isValid (Location A);
        void V2canCreatePoint();
        void H2canCreatePoint();
        void V3canCreatePoint();
        void H3canCreatePoint();
        void V4canCreatePoint();
        void H4canCreatePoint();
        void V5canCreatePoint();
        void H5canCreatePoint();
        void AIV2canCreatePoint();
        void AIH2canCreatePoint();
        void AIV3canCreatePoint();
        void AIH3canCreatePoint();
        void AIV4canCreatePoint();
        void AIH4canCreatePoint();
        void AIV5canCreatePoint();
        void AIH5canCreatePoint();
        bool isAlive();
};


void Grid::makegrid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = '.';
        }
    }
}

void Grid::printgrid()
{
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Grid::changePoint (Location choice, char mark)
{
    grid[choice.getX()][choice.getY()] = mark;
}

void Grid::checkandchangePoint(Grid &A, Location choice)
{
    A.changePoint(choice,checkPoint(choice));
}

char Grid::checkPoint(Location choice)
{
    if (grid[choice.getX()][choice.getY()] == '.')
    {
        cout << "MISS!" << endl;
        return 'X';
    }
    else if (grid[choice.getX()][choice.getY()] == 'S')
    {
        cout << "HIT!" << endl;
        return '!';
    }
    else
    {
        cout << "Point Already Chosen, place choose another" << endl;
        int uX = 0;
        int uY = 0;
        cin >> uX;
        cin >> uY;
        choice.setX(uX);
        choice.setY(uY);
    }
}

bool Grid::isValid(Location A)
{
    if (grid[A.getX()][A.getY()] != '.')
    {
        return false;
    }
    else 
    {
        return true;
    }
}

void Grid::H2canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize2Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s2getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s2getPoint(i), 'S');
            }
        }
    }
}

void Grid::V2canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize2Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s2getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s2getPoint(i), 'S');
            }
        }
    }    
}

void Grid::H3canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize3Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s3getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s3getPoint(i), 'S');
            }
        }
    }
}

void Grid::V3canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize3Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s3getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s3getPoint(i), 'S');
            }
        }
    }
}

void Grid::H4canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize4Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s4getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s4getPoint(i), 'S');
            }
        }
    }
}

void Grid::V4canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize4Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s4getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s4getPoint(i), 'S');
            }
        }
    }
}

void Grid::H5canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize5Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s5getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s5getPoint(i), 'S');
            }
        }
    }
}

void Grid::V5canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize5Ship ship1;
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s5getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s5getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIH2canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize2Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s2getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s2getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIV2canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize2Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s2getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s2getPoint(i), 'S');
            }
        }
    }    
}

void Grid::AIH3canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize3Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s3getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s3getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIV3canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize3Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s3getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s3getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIH4canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize4Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s4getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s4getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIV4canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize4Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s4getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s4getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIH5canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        HSize5Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s5getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s5getPoint(i), 'S');
            }
        }
    }
}

void Grid::AIV5canCreatePoint()
{
    bool flag = false;
    while (!flag)
    {
        VSize5Ship ship1((rand() % 10), (rand() % 10));
        for (int i = 0; i < ship1.getSize(); i++)
        {
            flag = isValid(ship1.s5getPoint(i));
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < ship1.getSize(); i++)
            {
                changePoint(ship1.s5getPoint(i), 'S');
            }
        }
    }
}

bool Grid::isAlive()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == 'S')
            {
                return true;
            }
        }
    }
    return false;
}

#endif