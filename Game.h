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
#include "Move_pos.h"

class Game {
private:
    const bool game_won = true;
    const bool valid_move_reset = true;
    const int robot_move_place = 0; //used to determine the robts vertical and horizontal movement in robot_movement
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
    const char door = 'O';
public:
    Game(const std::string & filename);
    bool play(); // implements the game loop; returns true if player wins, false otherwise
    void showGameDisplay();
    void player_movement();
private:
    Maze getMaze() const;
    Player getPlayer() const;
    std::vector<Robot> getRobots() const;
    std::vector<Post> getPosts() const;
    bool getGameWin() const;
    void setGameWin(bool gameCond);
    bool collide_robot_1(Robot& robot, Post& post); // check if robot collided with post (and possibly set it as dead)
    bool collide_robot_2(Robot& robot, Player& player); // check if human and robot collided (and possibly set human as dead)
    // other methods, for example:
    // to check if player is trying to move to a valid place
    // to apply a valid play and check collisions
    // to check if two robots collide (and possibly set them as dead)
    // etc.
    void robot_movement();
private:
    Maze maze;
    Player player;
    std::vector<Robot> robots;
    std::vector<Post> posts;
    bool gameWin;
};

#endif