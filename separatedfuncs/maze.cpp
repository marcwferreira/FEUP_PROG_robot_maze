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
#include "maze.h" //this file

using namespace std;

//Load maze in the console
void maze(int maze_num,game_info &gameplay) {

    string maze_select;

    //select maze txt file
    maze_select = maze_name(maze_num, game_file);

    ifstream mazefile;
    mazefile.open(maze_select);

    string line; //lines of the file
    int pos_x, pos_y; //vars to get map size
    int count_robot = 0;//count the robots in the game

    if(!mazefile.is_open()){
        cout << "ERROR!" << endl;
    }
    else{

        //get the size of the maze
        mazefile >> pos_y;
        mazefile.ignore ( std::numeric_limits<std::streamsize>::max(), 'x' );
        mazefile >> pos_x;

        //count the number of robots
        while (getline(mazefile, line)) {
            int line_len = line.length();
            for(int i=1; i < line_len; i++){
                if(line[i] == alive_robot){
                    count_robot++;
                }
            }
        } mazefile.close();

    }

    //clearing vectors and preparing then to be resized (in the case player wants to replay)
    gameplay.maze_map.clear();
    gameplay.maze_map.shrink_to_fit();
    gameplay.player_pos.clear();
    gameplay.player_pos.shrink_to_fit();
    gameplay.robot_info.clear();
    gameplay.robot_info.shrink_to_fit();

    //resizing the vector in gameplay to appropriate size
    gameplay.maze_map.resize(pos_y,vector<char>(pos_x));
    gameplay.player_pos.resize(2);//vector with line and collumn position of player
    gameplay.robot_info.resize(count_robot,vector<int>(3));//vector with line, collumn positions and condition of robot

    int map_line = 0; //counting the lines
    int robot_index = 0; //help indexing the robot_info

    //getting the map into a vector
    mazefile.open(maze_select);
     if(!mazefile.is_open()){
        cout << "ERROR!" << endl;
    }
    else{
        mazefile.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
        while(getline(mazefile,line)){
            for(int i=0; i < pos_x; i++){
                gameplay.maze_map[map_line][i] = line[i];
            }

            map_line++;
        }
        mazefile.close();
    }

    //finding player and robot positions
    for(int i=0;i<pos_y;i++){
        for(int j=0;j<pos_x;j++){
            cout << gameplay.maze_map[i][j];

            //find player position in the map
            if(gameplay.maze_map[i][j] == alive_player){
                gameplay.player_pos[0] = i;
                gameplay.player_pos[1] = j;
            }
            //find robots positions in the map
            else if(gameplay.maze_map[i][j] == alive_robot){
                gameplay.robot_info[robot_index][0] = i; //robot line position
                gameplay.robot_info[robot_index][1] = j; //robot column position
                gameplay.robot_info[robot_index][2] = 1; //robot condition, 1 means the robot is alive

                robot_index++;
            }
        }
        cout << endl;
    }

    //Return to main menu
    if (maze_num == invalid_maze_num) {
        game_start();
    }
}
