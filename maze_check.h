//T09_G12

#ifndef MAZE_CHECK_H
#define MAZE_CHECK_H

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

//Function for the main menu - returns options chosen by the user
bool maze_check(int maze_num, bool winner_check);

//constants
const bool game_file = false;
const bool winner_file = true;

#endif