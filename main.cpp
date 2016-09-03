#include "grid.h"
#include "UI.h"
#include "player.h"


int main()
{
    int uX = 0;
    int uY = 0;
    Player Human;
    AI enemyAI;
    Grid playerScreen;
    Grid playerAttkScreen;
    Grid AIScreen;
    Location playerattk;
    playerScreen.makegrid();
    playerAttkScreen.makegrid();
    AIScreen.makegrid();
    
    
    Human.placeShip(playerScreen);
    enemyAI.placeShip(AIScreen);
    AIScreen.printgrid();
    cout << endl << "------------------------------------------------------" << endl;
    playerScreen.printgrid();
    
    while (playerScreen.isAlive() && AIScreen.isAlive())
    {
        cout << "Choose where you want to attack " << endl;
        cin >> uX;
        cin >> uY;
        playerattk.setX(uX);
        playerattk.setY(uY);

       
        
        Human.attack(AIScreen, uX, uY);
        enemyAI.attack(playerScreen);
        AIScreen.printgrid();
        cout << endl << "------------------------------------------------------" << endl;
        playerScreen.printgrid();
    }
    
    if (playerScreen.isAlive())
    {
        cout << "WINNER!" << endl;
    }
    else
    {
        cout << "LOSER..." << endl;
    }
   
    return 0;
}