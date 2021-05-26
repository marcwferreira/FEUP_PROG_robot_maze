#include <iostream>
#include <string>
#include <list>
#include "Position.h"

using namespace std;

class GameObject
{
public:
    GameObject() {}

    Position getPosition() { return p; }
    void setPosition(int X, int Y) { p.setX(X); p.setY(Y); }
    bool getState() { return state; }

    void setState(bool value) { state = value; }

    void movement() {

        //p.setPosition(i, j);
    }

private:
    Position p;
    bool state = true;
};


