#ifndef FUNCTIONS
#define  FUNCTIONS
#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include <random>

std::random_device rd;
int getRandom(int lower, int upper);
int mineAround(int x,int y);
void initialize(int mineAmount);
bool revealedEmptyNeighbor(int x, int y);
bool checkNeighbours();
void display(bool debug);
bool userInput(int& counter);
enum Allocation{
    HIDDEN,
    REVEALED,
    MINE
};
struct Tile {
    Allocation status = HIDDEN;
    int mineAround = 0;
};
#endif

