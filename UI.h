#ifndef UI_H
#define UI_H
#include <iostream>
using namespace std;

void intro ()
{
   
    cout << "Welcome to Battlship!" << endl;
    cout << "You have 5 ships: " << endl;
    cout << "2x Size 2 ships " << endl << "1x Size 3 ship" << endl << "1x Size 4 ship" << endl << "1x size 5 ship" << endl;
    cout << "Choose whether you want it placed Horizontally or Vertically by pressing H or V respectively, x will exit the game completely, and any other key will be ignored." << endl;


}

char chooseOrientation()
{
    cout << "Choose Orientation" << endl;
    char userOrientation = 'A';
    cin >> userOrientation;
    while (userOrientation != 'h' && userOrientation != 'v' && userOrientation != 'x')
    {
        if (userOrientation == 'h')
        {
            return 'h';
        }
        else if (userOrientation == 'v')
        {
            return 'v';
        }
        else
        {
            return 'x';
        }
        cout << "Try Again." << endl;
        cin >> userOrientation;
    }
}
#endif