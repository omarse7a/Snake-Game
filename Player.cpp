#include "Components.h"

Player::Player() {
	score = 0;
	cout << "Enter Player Name: ";
	cin >> name;
}

void Player::incrementScore() {
	score += 10;
}

int Player::getScore() const{
	return score;
}

string Player::getName() const
{
	return name;
}
