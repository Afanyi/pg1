#include "battleship.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Battleship::Battleship(const string& player1Name, const string& player2Name):m_players{Player(player1Name),Player(player2Name)}{

}

void Battleship::play(){
    for (int i=0;i<=1;i++) {
        cout << m_players[i].getName() << " has " << m_players[i].getGamesWon() << "wins and "
             << m_players[i].getGamesLost() << " loses" << endl;

        m_boards[i] = GameBoard();
        m_boards[i].randomPlaceShips();

        cout << m_players.at(i).getName() << "'s  board" << endl;
        m_boards[i].printBoard();

    }
    bool hit;
    int row;
    int col;
    int turn = 0;

    while (not (m_boards[0].allShipsSunk() or m_boards[1].allShipsSunk())) {
        turn = turn % 2;
        std::cout << m_players[turn].getName() << " turn.\r\n";
        cout << " enter x coord to hit : ";
        cin >> row;
        cout << " enter y coord to hit : ";
        cin >> col;
        hit = m_boards[turn].hit(row,col);
        if(hit)
            cout << " you touched a Ship " << endl;
        else
            cout << " you missed "<< endl;

        m_boards[turn].mark(row,col,hit);
        m_boards[turn].printBoard();
        cout << endl;
        m_boards[(turn+1)%2].printEnemyBoard();
        turn ++;
        }
    if (m_boards[0].allShipsSunk()) {
        cout << m_players[1].getName() << " wins";
        m_players[0].addGameLost();
        m_players[1].addGameWon();
    }
    else {
        cout << m_players[0].getName() << " wins";
        m_players[1].addGameLost();
        m_players[0].addGameWon();
    }
}



