//T09_G12

#ifndef POST_H
#define POST_H

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

//store the posts in the map
class Post {
public:
    Post(int row_input, int col_input, char type_input);
    int getRow() const;
    int getCol() const;
    char getSymbol() const; // get char representation of Post
    void setType(char type_set);
    bool isElectrified() const; //returns if post is electrified
private:
    int row, col;
    char type; // '*' - electrified; '+'- non-electrified
};

//constants
const char electric = '*';
const char nonelectric = '+';
const char door = 'O';

#endif