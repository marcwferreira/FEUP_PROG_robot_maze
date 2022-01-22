//T09_G12

#ifndef MOVE_POS_H
#define MOVE_POS_H

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

//store info about where a player and a robot is going to move
struct Movement{
    int dRow, dCol; // displacement, taking into account the chosen movement
};

//store coordinate info
struct Position{
    int row, col;
};


#endif