#include <iostream>
#include "Player.h"
#include "Movement.h"

Player::Player(int row, int col, char symbol){
	row = row;
	col = col;
	symbol = symbol;
}
int Player:: getRow() const {
	return row;
}
int Player::getCol() const {
	return col;
}
char Player::getSymbol() const {
	return symbol;
}
bool Player::isAlive() const {
	return alive;
}
void Player::setAsDead() {
	alive = false;
}
bool move(Movement delta){

}