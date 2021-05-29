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
#include "Gate.h"
#include "Move_pos.h"

//constructor
Gate::Gate(int row_input, int col_input) {
    row = row_input;
    col = col_input;
}

//getter
int Gate::getRow() const { return row; }
int Gate::getCol() const { return col; }
char Gate::getSymbol() const { return gate_symbol; }