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

struct Movement{
    int dRow, dCol; // displacement, taking into account the chosen movement
};

struct Position{
    int row, col;
};


#endif