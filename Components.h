#pragma once
#include <iostream>
using namespace std;

class Snake
{
private:
	int headX, headY;
public:
	Snake();
	int getPosX();
	int getPosY();
};

class Map
{
private:
	int width, height, fruitX, fruitY;
public:
	Map();
	void generateFruit();
	void draw(Snake* sPtr);
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

