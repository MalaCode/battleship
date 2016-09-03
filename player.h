#include <iostream>
#include "grid.h"
#include "UI.h"
#include <stdlib.h>
using namespace std;

int taken_Counter = 0;
int AItaken_Counter = 0;

class Player
{
    protected:
        int turn;
        Location takenMoves [81];
    public:
        void setTurn(int t);
        int getTurn();
        bool attackisValid(Location A);
        void attack(Grid &A, int uX, int uY);
        void placeShip(Grid &A);
        void createSize2Ship (Grid &A, char orientation);
        void createSize3Ship (Grid &A, char orientation);
        void createSize4Ship (Grid &A, char orientation);
        void createSize5Ship (Grid &A, char orientation);
};

void Player::setTurn(int t)
{
    turn = t;
}

int Player::getTurn()
{
    return turn;
}

bool Player::attackisValid(Location A)
{
    for (int i = 0; i < 81; i++)
    {
        if (takenMoves[i].getX() == A.getX() && takenMoves[i].getY() == A.getY())
        {
        return false;
        }
    }
    if (A.getX() > 9 || A.getX() < 0 || A.getY() > 9 || A.getY() < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Player::attack(Grid &A, int uX, int uY)
{
    Location choice;
    choice.setX(uX);
    choice.setY(uY);
    flag bad;
    if (attackisValid(choice))
    {
        takenMoves[taken_Counter] = choice;
        taken_Counter++;
        A.checkandchangePoint(A, choice);
        return;
    }
    else
    {
        cout << "Attack is not Valid, Try Again " << endl;
        cin >> uX;
        
        cin >> uY;
        attack(A, uX, uY);
    }
}

void Player::placeShip(Grid &A)
{
    char orientation = '-';
    intro();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ship1
    cout << "Do you want a Horizontal or Verticle ship?" << endl;
    createSize2Ship(A, orientation);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship2
    cout << "Do you want a Horizontal or Verticle ship?" << endl;
    createSize2Ship(A, orientation);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship3
    cout << "Do you want a Horizontal or Verticle ship?" << endl;
    createSize3Ship(A, orientation);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship4
    cout << "Do you want a Horizontal or Verticle ship?" << endl;
    createSize4Ship(A, orientation);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship5
    cout << "Do you want a Horizontal or Verticle ship?" << endl;
    createSize5Ship(A, orientation);
}

void Player::createSize2Ship(Grid &A, char orientation)
{
    orientation = chooseOrientation();
    if (orientation == 'h')
    {
        A.H2canCreatePoint();
        return;
    }
    else if (orientation == 'v')
    {
        A.V2canCreatePoint(); 
        return;
    }
    else
    {
        cout << "Incorrect Input, Try Again " << endl;
        cin >> orientation;
        createSize2Ship(A, orientation);
    }
}

void Player::createSize3Ship(Grid &A, char orientation)
{
    orientation = chooseOrientation();
    if (orientation == 'h')
    {
        A.H3canCreatePoint();
        return;
    }
    else if (orientation == 'v')
    {
        A.V3canCreatePoint(); 
        return;
    }
    else
    {
        cout << "Incorrect Input, Try Again " << endl;
        cin >> orientation;
        createSize3Ship(A, orientation);
    }
}

void Player::createSize4Ship(Grid &A, char orientation)
{
  orientation = chooseOrientation();
    if (orientation == 'h')
    {
        A.H4canCreatePoint();
        return;
    }
    else if (orientation == 'v')
    {
        A.V4canCreatePoint(); 
        return;
    }
    else
    {
        cout << "Incorrect Input, Try Again " << endl;
        cin >> orientation;
        createSize4Ship(A, orientation);
    }
}    

void Player::createSize5Ship(Grid &A, char orientation)
{
    orientation = chooseOrientation();
    if (orientation == 'h')
    {
        A.H5canCreatePoint();
        return;
    }
    else if (orientation == 'v')
    {
        A.V5canCreatePoint(); 
        return;
    }
    else
    {
        cout << "Incorrect Input, Try Again " << endl;
        cin >> orientation;
        createSize5Ship(A, orientation);
    }
}

class AI : public Player
{
    public:
        void attack(Grid &A);
        char pickOrientation();
        void placeShip(Grid &A);
        
};

void AI::attack(Grid &A)
{
    Location choice;
    int uX = rand() % 10;
    int uY = rand() % 10;
    choice.setX(uX);
    choice.setY(uY);
    if (attackisValid(choice))
    {
        takenMoves[AItaken_Counter] = choice;
        AItaken_Counter++;
        A.checkandchangePoint(A, choice);
    }
    else
    {
        attack(A);
    }
  
}

char AI::pickOrientation()
{
    int x = rand() % 2;
    if (x == 1)
    {
        return 'h';
    }
    else
    {
        return 'v';
    }
}

void AI::placeShip(Grid &A)
{
    char orientation = '-';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ship1
    orientation = pickOrientation();
    if (orientation == 'h')
    {
        A.AIH2canCreatePoint();
    }
    else if (orientation == 'v')
    {
        A.AIV2canCreatePoint(); 
    }
    else
    {
        return;    
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship2
    orientation = pickOrientation();
    if (orientation == 'h')
    {
        A.AIH2canCreatePoint();
    }
    else if (orientation == 'v')
    {
        A.AIV2canCreatePoint(); 
    }
    else
    {
        return;    
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship3
    orientation = pickOrientation();
    if (orientation == 'h')
    {
        A.AIH3canCreatePoint();
    }
    else if (orientation == 'v')
    {
        A.AIV3canCreatePoint(); 
    }
    else
    {
        return;    
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship4
    orientation = pickOrientation();
    if (orientation == 'h')
    {
        A.AIH4canCreatePoint();
    }
    else if (orientation == 'v')
    {
        A.AIV4canCreatePoint(); 
    }
    else
    {
        return;    
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ship5
    orientation = pickOrientation();
    if (orientation == 'h')
    {
        A.AIH5canCreatePoint();
    }
    else if (orientation == 'v')
    {
        A.AIV5canCreatePoint(); 
    }
    else
    {
        return;    
    }
}
