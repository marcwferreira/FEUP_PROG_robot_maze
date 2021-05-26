#include <iostream>
#include <string>
#include <list>
#include "GameObject.h"

using namespace std;

class Robot :
    public GameObject
{
public:
    Robot() :GameObject() {};

    int getrobot_index() { return robot_index; }

    void RobotMovement() {

        movement();
    }

private:

    int robot_index;
};


