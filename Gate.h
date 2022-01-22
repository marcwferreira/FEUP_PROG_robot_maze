//T09_G12

#ifndef GATE_H
#define GATE_H

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

//store the gates that exist in the map
class Gate {
public:
    Gate(int row_input, int col_input);
    int getRow() const;
    int getCol() const;
    char getSymbol() const;
private:
    int row, col;
};

const char gate_symbol = 'O';

#endif