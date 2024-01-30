#include "Components.h"

/*This constructor puts the head of the snake at the center, adjusting dir to STOP*/
Snake::Snake() : head({ HEIGHT / 2, WIDTH / 2 }), dir(STOP), gameOver(false) {}

/*Setting the snake's head and tail on the 2D array map*/
void Snake::setOnMap(Map* mPtr) {
	mPtr->setCell(head.first, head.second, 'O'); // setting the head symbol
	for (int i = 0; i < body.size(); i++) {
		mPtr->setCell(body[i].first, body[i].second, 'o'); // setting the body part symbol
	}
}

/*Determining the snake's direction according to the key clicked*/
void Snake::getDirection() {
	if (_kbhit()) { // returns true if a key is clicked
		switch (_getch()) //determines which key is clicked
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
		case 'x':	//pressing "x" ends the game immediately
			gameOver = true;
			break;
		}
	}
}

/*This function handles the logic of snake's movement, fruit eating*/
void Snake::move(Map* mPtr, Player* pPtr) {
	if(dir != STOP)
	{
		/*simulating the snake's movement for the body parts by adding the old head position
		to the body deque from the front and removing a body part from the the back*/
		if(!body.empty()) {
			body.push_front(head);
			body.pop_back();
		}
		//updating the snake's head position according to value of dir
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
		//Checking snake's collisions on the boundaries
		if (head.first == HEIGHT + 1 || head.first == 0
			|| head.second == WIDTH + 1 || head.second == 0) {
			gameOver = true;
		}
		//Checking snake's collisions with itself
		for (int i = 0; i < body.size(); i++) {
			if (head.first == body[i].first && head.second == body[i].second) {
				gameOver = true;
			}
		}
		//eating the fruit
		if (head.first == mPtr->getFoodPos().first && head.second == mPtr->getFoodPos().second) {
			pPtr->incrementScore();
			grow();
			mPtr->generateFruit();	//generating a new fruit
		}
	}
}

/*Growing the snake by adding a body part from the back according to the direction*/
void Snake::grow() {
	pair<int, int> tail = body.empty()? head : body.back();	//determing the tail of the snake
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

/*Ending the game*/
bool Snake::game_is_over() const
{
	return gameOver;
}
