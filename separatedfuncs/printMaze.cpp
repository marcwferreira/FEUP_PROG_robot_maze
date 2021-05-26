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
#include "teste.h"
#include "maze.h"
#include "printMaze.h"

using namespace std;

//Prints maze map when called
void print_maze(game_info &gameplay){

    for(int i=0;i<gameplay.maze_map.size();i++){
        for(int j=0;j<gameplay.maze_map[i].size();j++){
            printf("%c",gameplay.maze_map[i][j]);
        }
        printf("\n");
    }
}
