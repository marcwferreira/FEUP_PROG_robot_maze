//T09_G12

#ifndef MAZE_H
#define MAZE_H

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

#include "main.cpp" //deal with this later

//Load maze in the console
void maze(int maze_num,game_info &gameplay);

const bool game_file = false;//indicates that this is a maze file and not a winner file
const int invalid_maze_num = 0;
const char alive_player = 'H';
const char alive_robot = 'R';

#endif