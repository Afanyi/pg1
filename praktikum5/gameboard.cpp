#include <iostream>
#include "gameboard.h"
#include <random>
using std::to_string;
using std::string;
using std::cout;
using std::endl;



int GameBoard::getRandom(int upperBound) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, upperBound);
    return dist(rd);
}

GameBoard::GameBoard(){
    for(int i=0;i<10;i++){
        for (int j=0; j<10;j++) {
            m_enemyBoard[i][j] = water;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int n = 0; n < 10; n++) {
            m_Board[i][n] = unTouched;
        }
    }

};
bool GameBoard::allShipsSunk(){
    for(auto&  s : m_ships){
        if(!(s.isSunk())){
            return false;
        }
    }
    return true;
}
void GameBoard::randomPlaceShips(){
    srand(time(nullptr));
    std::vector<Direction> availableDirections = {Direction::north, Direction::south, Direction::west, Direction::east};

    std::vector<int> length = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2};
    int i=0;

    while(i < length.size()){
        Retry:
        int _direction = 1;
        Direction direction = availableDirections[getRandom(3)];
            int x = getRandom(9);
            int y = getRandom(9);
            for (auto& ship : m_ships) {
                if (ship.hasPartIn(x,y))
                    goto Retry;

                if (direction == Direction::north or direction == Direction::west)
                    _direction = -1;

                for (int n=0; n<length[i];n++) {
                    if (direction == Direction::north or direction == Direction::south) {
                        if (ship.hasPartIn(x,y + n * _direction) or y +  length[i]  * _direction  > 9 or y +  length[i]  * _direction < 0)
                            goto Retry;
                    }
                    else {
                        if (ship.hasPartIn(x + n * _direction, y)  or x +  length[i]  * _direction  > 9 or x +  length[i]  * _direction < 0)
                            goto  Retry;
                    }
                }


            }
            m_ships.at(i) = Ship(x, y, length[i], direction);
            i++;
        }


}

void GameBoard::printBoard(){

    for(int i=0; i<10;i++){
        for(int j=0; j<10; j++){
            if(shipPresent(i,j)){
                for(int k=0;k<m_ships.size();k++){
                    if(m_ships[k].hasPartIn(i, j)){
                        m_ships[k].getPartIn(i,j).isDamaged();
                        if (m_ships[k].isSunk())
                            m_Board[i][j] = sinkedShip;

                        else if(m_ships[k].getPartIn(i, j).isDamaged())
                            m_Board[i][j] = damagePart;

                        else
                            m_Board[i][j] = k + '0'; // should be the index as ascii char
                    }
                }
            }
            else{
                m_Board[i][j] = '.';
            }
        }
    }
    PrintBoardHelper(m_Board);
}
bool GameBoard::shipPresent(int row, int col){
    for(Ship s : m_ships){
        if(s.hasPartIn(row,col)){
            return true;
        }
    }
    return false;
};
bool GameBoard::hit(int row, int col){
    if (row > 9 or row < 0 or col > 9 or col < 0)
        throw std::invalid_argument("col/row out of board");

    for(auto & m_ship : m_ships){
        if(m_ship.hasPartIn(row,col)){
            m_ship.getPartIn(row,col).setDamaged();
            return true;
        }
    }
    return false;}

void GameBoard::printEnemyBoard(){
    PrintBoardHelper(m_enemyBoard);
}

void GameBoard::PrintBoardHelper(array<array<char, 10>, 10> board) {
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            std::cout << board[j][i] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void GameBoard::mark(int row, int col, bool wasHit){
    if(wasHit){ //
        m_enemyBoard[row][col] = partHere;
    }
    else {
        m_enemyBoard[row][col] = nothingHere;
    }
}
