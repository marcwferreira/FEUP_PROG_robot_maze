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
#include "Maze.h"

//constructors
Maze::Maze(){
    numRows = -1;
    numCols = -1;
}
Maze::Maze(int numrows, int numcols){
    numRows = numrows;
    numCols = numcols;
}

//getters
int Maze::getnumRows() const {return numRows;}
int Maze::getnumCols() const {return numCols;}

//setter
void Maze::setnumRows(int numrows) {
    numRows = numrows;
}
void Maze::setnumCols(int numcols) {
    numCols = numcols;
}