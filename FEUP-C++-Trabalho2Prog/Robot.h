#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <list>
#include "GameObject.h"

using namespace std;

class Robot :
    public GameObject
{
public:
    Robot();

    int getrobot_index();

    void RobotMovement();

private:

    int robot_index;
};

#endif



