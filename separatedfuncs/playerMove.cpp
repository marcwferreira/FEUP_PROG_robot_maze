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
#include "playerMove.h"

using namespace std;

//Player movement
void player_move(game_info &gameplay) {

    string player_move; //variable to detect player movement
    bool movement_completed = false;

    int change_x = 0, change_y = 0; //to where we need to move relative where we are
    int s_move = 0; //verifies if it is an s input (choose not to move)
    bool valid_move = valid_move_reset; //if move is valid we do it and break from the loop

    cout << endl << "Where do you want to go?" << endl;
    while(!movement_completed){

        //reset move validation and move positions
        valid_move = valid_move_reset;//flag for invalid movement
        change_x = 0; //means no movement in x asix
        change_y = 0; //means no movment in y axis

        //get player input
        cin >> player_move;
        cin.ignore(255,'\n');

        //end the program if user press control + z
        if(cin.eof()){
            std::exit(0);
        }

        //determine which char the player chose and validates it
        if(player_move == "q" || player_move == "Q"){
            change_y = move_position_negative;
            change_x = move_position_negative;
        }
        else if(player_move == "w" || player_move == "W"){
           change_y = move_position_negative;
        }
        else if(player_move == "e" || player_move == "E"){
            change_y = move_position_negative;
            change_x = move_position_positive;
        }
        else if(player_move == "a" || player_move == "A"){
        change_x = move_position_negative;
        }
        else if(player_move == "s" || player_move == "S"){
            s_move = detect_s_move;
        }
        else if(player_move == "d" || player_move == "D"){
            change_x = move_position_positive;
        }
        else if(player_move == "z" || player_move == "Z"){
            change_y = move_position_positive;
            change_x = move_position_negative;
        }
        else if(player_move == "x" || player_move == "X"){
            change_y = move_position_positive;
        }
        else if(player_move == "c" || player_move == "C"){
            change_y = move_position_positive;
            change_x = move_position_positive;
        }
        else{
            valid_move = detect_invalid_move;//flag for invalid movement
        }

        //if valid checks where it is going and its consequences
        if(valid_move == valid_move_reset){
            //player tries to move into dead robot
            if(gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] == dead_robot){
                valid_move = detect_invalid_move;
            }
            //player hits wall or robt
            else if(gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] == wall || gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] == alive_robot){
                gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] = dead_player;
                if(s_move != detect_s_move){
                gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] = empty_map_space;
                }
                gameplay.player_pos[line] = gameplay.player_pos[line]+change_y;
                gameplay.player_pos[column] = gameplay.player_pos[column]+change_x;
                movement_completed = true;
            }
            //player moves normally
            else{
                gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] = alive_player;
                if(s_move != detect_s_move){
                    gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] = empty_map_space;
                }
                gameplay.player_pos[line] = gameplay.player_pos[line]+change_y;
                gameplay.player_pos[column] = gameplay.player_pos[column]+change_x;
                movement_completed = true;
            }
        }

        //if not valid tells the user and restart the loop
        if(valid_move == detect_invalid_move){
            cout << "Movement invalid, please choose another one" << endl;
        }
    }
}
