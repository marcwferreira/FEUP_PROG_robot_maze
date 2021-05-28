#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <list>
#include "Position.h"

using namespace std;

class GameObject
{
public:
    GameObject();

    void setPosition(int X, int Y);
    Position getPosition();
    bool getState();

    void setState(bool value);


public:
    Position p;
    bool state = true;
};

#endif


