#include <iostream>
#include "GameObject.h"
#include "Position.h"

using namespace std;

GameObject::GameObject() {}

void GameObject::setPosition(int X, int Y) { p.setX(X); p.setY(Y); }
bool GameObject::getState() { return state; }

void GameObject::setState(bool value) { state = value; }

