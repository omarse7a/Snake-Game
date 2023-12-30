#include "Components.h"

Player::Player() {
	score = 0;
}

void Player::incrementScore() {
	score += 10;
}

int Player::getScore() {
	return score;
}
