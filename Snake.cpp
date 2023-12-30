#include "Components.h"

Snake::Snake() : head({ HEIGHT / 2, WIDTH / 2 }), dir(STOP), gameOver(false) {}

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
			if(dir != DOWN)
				dir = UP;
			break;
		case 's':
			if(dir != UP)
				dir = DOWN;
			break;
		case 'd':
			if (dir != LEFT)
				dir = RIGHT;
			break;
		case 'a':
			if (dir != RIGHT)
				dir = LEFT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Snake::move(Map* mPtr, Player* pPtr) {
	if(dir != STOP)
	{
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
		if (head.first == HEIGHT + 1 || head.first == 0
			|| head.second == WIDTH + 1 || head.second == 0) {
			gameOver = true;
		}
		if (head.first == mPtr->getFoodPos().first && head.second == mPtr->getFoodPos().second) {
			mPtr->generateFruit();
			pPtr->incrementScore();
			grow();
		}
		for (int i = 0; i < body.size(); i++) {
			body.push_front(tempPos);
			body.pop_back();
		}
		Sleep(100);
	}
}

void Snake::grow() {
	pair<int, int> tail = body.empty()? head : body.back();
	switch (dir) {
	case UP:
		body.push_back({ tail.first - 1, tail.second });
		break;
	case DOWN:
		body.push_back({ tail.first + 1, tail.second });
		break;
	case RIGHT:
		body.push_back({ tail.first, tail.second + 1 });
		break;
	case LEFT:
		body.push_back({ tail.first, tail.second - 1 });
		break;
	default:
		break;
	}
}


bool Snake::game_is_over()
{
	return gameOver;
}
