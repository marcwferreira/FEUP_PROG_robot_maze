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
#include "player.h"
#include "move_pos.h"

player::player(int rowset, int colset, char symbolset){
    row = rowset;
    col = colset;
    symbol = symbolset;
}

int player::getrow(){
    return row;
}

int player::getcol(){
    return col;
}

char player::getsymbol(){
    return symbol;
}

void player::setsymbol(char playersymbol){
    symbol = playersymbol;
}

void player::move(movement delta){
    row = row + delta.drow;
    col = col + delta.dcol;
}

bool player::alive(){
    if (symbol == player_alive){
        return true;
    }
    else{
        return false;
    }
}