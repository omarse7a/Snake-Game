#include "Components.h"

Snake::Snake() : headX(25), headY(10){}

int Snake::getPosX() {
	return headX;
}
int Snake::getPosY() {
	return headY;
}