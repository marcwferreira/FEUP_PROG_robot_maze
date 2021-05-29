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

//our files
#include "Player.h"
#include "Move_pos.h"

//constructors
Player::Player(){
    row = 0;
    col = 0;
    alive = true;
    symbol = player_alive;
}
Player::Player(int row_input, int col_input){
    row = row_input;
    col = col_input;
    alive = true;
    symbol = player_alive;
}

//getters
int Player::getRow() const {return row;}
int Player::getCol() const {return col;}
char Player::getSymbol() const {return symbol;}

//setter
void Player::setRow(int row_set) {
    row = row_set;
}
void Player::setCol(int col_set) {
    col = col_set;
}


//functions
bool Player::isAlive() const {return alive;}
void Player::setAsDead() { //set player stat as dead
    alive = false;
    symbol = player_dead;
}
void Player::move(Movement delta){ //player movement function
    row = row + delta.dRow;
    col = col + delta.dCol;
}