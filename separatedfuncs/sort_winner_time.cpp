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

//our functions
#include "gameStart.h" 
#include "show_time_records.h"
#include "player_win.h"
#include "sort_winner_time.h"//this file

//function to determine sort function of a 2d vector - used in player_win
bool sort_winner_time(const vector<string>& v1, const vector<string>& v2);

    //comparing the times
    bool v1_less_than_v2 = v1[player_time] < v2[player_time];

    return v1_less_than_v2;
}