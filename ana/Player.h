#include <iostream>
#include <string>
#include <list>
#include "GameObject.h"

using namespace std;


class Player :
    public GameObject
{
public:

    Player() :GameObject() {};

    string getName() { return name; }
    time_t getTime() { return time; }


    void PlayerMovement() {

        movement();
    }

private:

    string name = "";
    time_t time;
};

