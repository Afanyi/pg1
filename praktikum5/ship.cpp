#include "ship.h"

Ship::Ship(){

};
Ship::Ship(int row, int col, int lengthOfShip, Direction direction){
    int _direction{1};
    if (direction  == Direction::north or direction == Direction::west)
        _direction = -1;

    for (int i=0; i<=lengthOfShip-1;i++) {
        if (direction  == Direction::north or direction == Direction::south) {
            isValid(col + i * _direction);
            m_parts.emplace_back(row,col + i * _direction);
        }
        else {
            isValid(row + i * _direction);
            m_parts.emplace_back(row + i * _direction, col);
        }
    }
}



bool Ship::hasPartIn(int row, int col){
    for(const auto& s : m_parts){
        if(row==s.getRow() && col==s.getCol())
            return true;
    }
    return false;
}

Part& Ship::getPartIn(int row, int col){
    for (auto& e: m_parts){
        if (e.getRow() == row and e.getCol() == col)
            return e;
    }
    throw std::invalid_argument("part not found");
}


bool Ship::isDamaged(){
    for(const auto& s : m_parts){
        if(s.isDamaged()){
            return true;
        }
    }
    return false;
}
bool Ship::isSunk(){
    for (const auto& e: m_parts) {
        if (not e.isDamaged())
            return false;
    }
    return true;
}


void Ship::isValid(int pos) {
    if (pos > 10 or pos < 0)
        throw std::invalid_argument("invalid input");
}