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
#include "sort_winner_time.h"

//function to determine sort function of a 2d vector - used in player_win
bool sort_winner_time(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {

    //comparing the times
    bool v1_less_than_v2 = v1[player_time] < v2[player_time];

    return v1_less_than_v2;
}