#include "Components.h"

Player::Player() {
	score = 0;
}

void Player::incrementScore() {
	score++;
}

int Player::getScore() {
	return score;
}