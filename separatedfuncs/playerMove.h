//T09_G12

#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H

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

//Player movement
void player_move(game_info &gameplay);

const bool valid_move_reset = true;
const int detect_invalid_move = false;
const int detect_s_move = 1;
const int move_position_positive = 1;
const int move_position_negative = -1;
const int line = 0; //player line
const int column = 1; //player column
const char alive_player = 'H';
const char dead_player = 'h';
const char alive_robot = 'R';
const char dead_robot = 'r';
const char wall = '*';
const char empty_map_space = ' ';

#endif