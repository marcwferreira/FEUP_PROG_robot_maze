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

class Post {
private:
    const char electric = '*';
    const char nonelectric = '+';
    const char door = 'O';
public:
    Post(int row_input, int col_input, char type_input);
    int getRow() const;
    int getCol() const;
    char getSymbol() const; // get char representation of Post
    bool isElectrified() const; 
    bool isDoor() const;
private:
    int row, col;
    char type; // '*' - electrified; '+'- non-electrified
};


#endif