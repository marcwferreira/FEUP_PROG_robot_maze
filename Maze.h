//T09_G12

#ifndef MAZE_H
#define MAZE_H

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

class Maze {
public:
    Maze();
    Maze(int numrows, int numcols);
    int getnumRows() const;
    int getnumCols() const;
    void setnumRows(int numrows);
    void setnumCols(int numcols);
private:
    int numRows, numCols;
};

#endif