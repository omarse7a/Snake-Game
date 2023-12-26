#pragma once
#include <iostream>
using namespace std;
class Map
{
private:
	int width, height, fruitX, fruitY;
public:
	Map();
	void generateFruit();
	void draw();
};

class Snake
{
private:
	int headX, headY;
public:
	Snake();
};

class Player
{
private:
	int score;
	bool gameOver;
public:
	Player();
	bool game_is_over();
};

class GameManager
{
private:
	Map* mapPtr;
	Snake* snakePtr;
	Player* playerPtr;
public:
	GameManager();
	void run();
};

