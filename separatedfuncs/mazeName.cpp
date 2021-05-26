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
#include "mazeName.h" //this file

using namespace std;

//makes the maze file name
string maze_name(int maze_num, bool winner_file){

    std::string maze;

    //select maze txt file
    if(winner_file == true){
        //select maze txt file for the winners
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + to_string(maze_num) + "_WINNERS.TXT";
        }
        else {
            maze = "MAZE_" + to_string(maze_num) + "_WINNERS.TXT";
        }
    }
    else{
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + to_string(maze_num) + ".TXT";
        }
        else {
            maze = "MAZE_" + to_string(maze_num) + ".TXT";
        }
    }

    return maze;
}
