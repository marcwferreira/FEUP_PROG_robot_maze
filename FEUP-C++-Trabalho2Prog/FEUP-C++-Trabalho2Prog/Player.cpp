#include <iostream>
#include "Player.h"
#include "GameObject.h"

using namespace std;

Player::Player(){};

string Player::getName() { return name; }
time_t Player::getTime() { return time; }


//void Player::PlayerMovement() { movement(); }
