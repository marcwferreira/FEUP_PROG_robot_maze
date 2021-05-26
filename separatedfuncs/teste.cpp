//T09_G12

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

//our functions
#include "gameStart.h"
#include "mazeName.h"
#include "teste.h" //this file

using namespace std;

//Test if the maze exists in the files
bool teste(int maze_num, bool winner_teste) {

    const bool game_file = false;//indicates that this will name a maze file and not a winner file
    const bool winner_file = true;
    
    bool flag_no_map = false;

    string maze;

    if(winner_teste == false){
        maze = maze_name(maze_num, game_file);
    }
    else if(winner_teste == true){
        maze = maze_name(maze_num, winner_file);
    }

    ifstream mazefile;
    mazefile.open(maze);
    if (mazefile.fail()) {
        flag_no_map = true;
    }

    return flag_no_map;
}
