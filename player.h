//T09_G12

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <iomanip>
#include <algorithm>

//our files
#include "Move_pos.h"

//store the player info
class Player {

public:
    Player();
    Player(int row, int col);
    int getRow() const;
    int getCol() const;
    char getSymbol() const;
    void setRow(int row_set);
    void setCol(int col_set);
    bool isAlive() const; //return if player is alive
    void setAsDead();   //set the player as dead
    void move(Movement delta);
private:
    int row, col;
    bool alive;
    char symbol;
};

//constants
const char player_alive = 'H';
const char player_dead = 'h';


#endif