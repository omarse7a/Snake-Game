#include "Components.h"

Snake::Snake() : head({HEIGHT / 2, WIDTH / 2 }), dir(STOP), gameOver(false) {}

pair<int, int> Snake::getPosition() {
	return head;
}

void Snake::setOnMap(Map* mPtr) {
	mPtr->setCell(head.first, head.second, 'O');
	for (int i = 0; i < body.size(); i++) {
		mPtr->setCell(body[i].first, body[i].second, 'o');
	}
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

void Snake::move(Map* mPtr) {
	pair<int, int> tempPos = head;
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
	if (head.first == HEIGHT+1 || head.first == 0
		|| head.second == WIDTH+1 ||head.second == 0) {
		gameOver = true;
	}
	if (head.first == mPtr->getFoodPos().first && head.second == mPtr->getFoodPos().second) {
		mPtr->generateFruit();
	}
	for (int i = 0; i < body.size(); i++) {
		body.push_front(tempPos);
		body.pop_back();
	}
	Sleep(100);
	
}

void Snake::grow()
{
	/*if (headX == mPtr->getFruitX() || headY == mPtr->getFruitY()) {
		pPtr->incrementScore();
		mPtr->generateFruit();
	}*/
}

bool Snake::game_is_over()
{
	return gameOver;
}
