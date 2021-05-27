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
#include "move_pos.h"

class player {
public:
    player(int row, int col, char symbol);
    int getrow();
    int getcol();
    char getsymbol(); 
    void setsymbol(char playersymbol); 
    void move(movement delta);
    bool alive();
private:
    int row;
    int col;
    char symbol;
};

const char player_alive = 'H';

#endif