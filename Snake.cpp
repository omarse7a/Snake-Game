#include "Components.h"

Snake::Snake() : head({HEIGHT / 2, WIDTH / 2 }), dir(STOP), gameOver(false) {}

pair<int, int> Snake::getPosition() {
	return head;
}

void Snake::setPosition(Map* mPtr) {
	mPtr->setCell(head.first, head.second, 'O');
}

void Snake::getDirection() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Snake::move(/*Map* mPtr,*/ Player* pPtr) {
	switch (dir)
	{
	case UP:
		head.first--;
		break;
	case DOWN:
		head.first++;
		break;
	case RIGHT:
		head.second++;
		break;
	case LEFT:
		head.second--;
		break;
	default:
		break;
	}
	/*if (headX == mPtr->getFruitX() || headY == mPtr->getFruitY()) {
		pPtr->incrementScore();
		mPtr->generateFruit();
	}*/
}

bool Snake::game_is_over()
{
	return gameOver;
}
