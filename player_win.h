//T09_G12

#ifndef PLAYER_WIN_H
#define PLAYER_WIN_H

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

//Player won - keep the time of his game
void player_win(int game_time, int maze_num);

const std::string save_yes = "1";
const std::string save_no = "0";
const int player_name_read = 0;
const int player_time_read = 1;
const int max_name_size = 15;



#endif
