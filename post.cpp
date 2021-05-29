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
#include "Post.h"
#include "Move_pos.h"

//constructor
Post::Post(int row_input, int col_input, char type_input){
    row = row_input;
    col = col_input;
    type = type_input;
}

//getter
int Post::getRow() const {return row;}
int Post::getCol() const {return col;}
char Post::getSymbol() const {return type;}

//setter
void Post::setType(char type_sel) {
    type = type_sel;
}

//functions
bool Post::isElectrified() const { //return if normal post or electrified (true if it is)
    if (type == electric){
        return true;
    }
    else{
        return false;
    }
}