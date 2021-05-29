//T09_G12

#ifndef GAME_H
#define GAME_H

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

//our files
#include "Maze.h"
#include "Player.h"
#include "Robot.h"
#include "Post.h"
#include "Gate.h"
#include "Move_pos.h"

class Game {
public:
    Game(const std::string & filename); //constructor that uses the filename of the maze
    bool play(); // implements the game loop; returns true if player wins, false otherwise
private:
    Maze getMaze() const;
    Player getPlayer() const;
    std::vector<Robot> getRobots() const;
    std::vector<Post> getPosts() const;
    std::vector<Gate> getGates() const;
    bool getGameWin() const; //gets the condition of the game (if player has won already)
    void setGameWin(bool gameCond); //gets the condition of the game (to signify player has won)
    bool ask_game_ended(); //function to detect is player win or lose
    void showGameDisplay(); //prints the display
    void player_movement();
    void robot_movement(int robot_index); //move the robot of id "robot_index"
private:
    Maze maze;
    Player player;
    std::vector<Robot> robots; //vector of the robots
    std::vector<Post> posts; //vector of the posts
    std::vector<Gate> gates; //vector of the doors in the map
    bool gameWin;
};

//constants
const bool game_start_cond = false;
const bool game_won = true;
const bool game_lost = false;
const bool game_ended = false;
const bool game_running = true;
const bool valid_move_reset = true;
const int robot_move_place = 0; //used to determine the robots vertical and horizontal movement in robot_movement
const int no_movement = 0;
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
const char electric_post = '*';
const char normal_post = '+';
//const char door = 'O';

#endif