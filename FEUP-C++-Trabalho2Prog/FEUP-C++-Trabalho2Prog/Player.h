#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <list>
#include "GameObject.h"

using namespace std;


class Player :
    public GameObject
{
public:

    Player();

    string getName();
    time_t getTime();


    //void PlayerMovement();

private:

    string name = "";
    time_t time;
};

#endif

