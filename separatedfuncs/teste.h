//T09_G12

#ifndef TESTE_H
#define TESTE_H

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
bool teste(int maze_num, bool winner_teste);

const bool game_file = false;//indicates that this will name a maze file and not a winner file
const bool winner_file = true;

#endif