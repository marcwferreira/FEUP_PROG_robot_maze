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
#include "post.h"

post::post(int rowsel, int colsel, char typesel){
    row = rowsel;
    col = colsel;
    type = typesel;
}

int post::getrow(){
    return row;
}

int post::getcol(){
    return col;
}

char post::getsymbol(){
    return type;
}

bool post::iselectrified(){
    if(type == electric_post){
        return true;
    }
    else{
        return false;
    }
}