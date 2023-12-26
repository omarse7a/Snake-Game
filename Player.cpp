#include "Components.h"

Player::Player() {
	score = 0;
	gameOver = false;
}

bool Player::game_is_over() {
	return gameOver;
}