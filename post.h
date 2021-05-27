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

//our files
#include "move_pos.h"

class post {
public:
 post(int row, int col, char type);
 int getrow();
 int getcol();
 char getsymbol(); // get char representation of Post
 bool iselectrified(); 
 //other methods
private:
 int row, col;
 char type; // '*' - electrified; '+'- non-electrified
};

const char electric_post = '*';

#endif