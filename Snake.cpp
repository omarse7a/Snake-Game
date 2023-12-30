#include "Components.h"

Snake::Snake() : head({ HEIGHT / 2, WIDTH / 2 }), dir(STOP), gameOver(false) {}

void Snake::setOnMap(Map* mPtr) {
	for (int i = 0; i < body.size(); i++) {
		mPtr->setCell(body[i].first, body[i].second, 'o');
	}
	mPtr->setCell(head.first, head.second, 'O');
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
		if(!body.empty()) {
			body.push_front(head);
			body.pop_back();
		}
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
		for (int i = 0; i < body.size(); i++) {
			if (head.first == body[i].first && head.second == body[i].second) {
				gameOver = true;
			}
		}
		if (head.first == mPtr->getFoodPos().first && head.second == mPtr->getFoodPos().second) {
			pPtr->incrementScore();
			mPtr->generateFruit();
			grow();
		}
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
