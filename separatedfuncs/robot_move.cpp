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
#include "show_time_records.h"
#include "player_win.h"
#include "sort_winner_time.h"
#include "play.h" 
#include "robot_move.h" //this file

//Robots movement
void robot_move(int robot_index, game_info& gameplay) {

    //variables to determine where the robot will move
    int change_x = 0;
    int change_y = 0;

    //determines if the robot will move up or down (will chase the player)
    if (gameplay.robot_info[robot_index][line] - gameplay.player_pos[line] > robot_move_place) {
        change_y = -1;
    }
    else if (gameplay.robot_info[robot_index][line] - gameplay.player_pos[line] < robot_move_place) {
        change_y = 1;
    }

    //determines if the robot will move left or right (will chase the player)
    if (gameplay.robot_info[robot_index][column] - gameplay.player_pos[column] > robot_move_place) {
        change_x = -1;
    }
    else if (gameplay.robot_info[robot_index][column] - gameplay.player_pos[column] < robot_move_place) {
        change_x = 1;
    }

    //MAKE THE ROBOTS MOVE
    //robot catches player and player
    if (gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] == alive_player) {
        gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] = dead_player;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
    }
    //robot dies in fence
    else if (gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] == wall) {
        gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line] + change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column] + change_x;
    }
    //robot colides with another and both get stuck
    else if (gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] == alive_robot) {
        gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line] + change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column] + change_x;
    }
    //got colides with stuck robot and get stuck
    else if (gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] == dead_robot) {
        gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line] + change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column] + change_x;
    }
    //robots move normally
    else {
        gameplay.maze_map[gameplay.robot_info[robot_index][line] + change_y][gameplay.robot_info[robot_index][column] + change_x] = alive_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line] + change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column] + change_x;
    }

}