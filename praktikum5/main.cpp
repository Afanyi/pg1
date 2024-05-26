#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

#include "battleship.h"
//#include "gameboard.h"
//#include "ship.h"
//#include "part.h"


int main()
{
    string player1Name;
    string player2Name;
    cout << "enter player1's name : ";
    cin >> player1Name;
    cout << "enter player2's name : ";
    cin >> player2Name;
    Battleship ground = Battleship(player1Name,player2Name);
    ground.play();
}



