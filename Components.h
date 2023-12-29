#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#define HEIGHT 25
#define WIDTH 40
using namespace std;

enum Direction { STOP = 0, UP, DOWN, RIGHT, LEFT };

class Player
{
private:
	int score;
public:
	Player();
	void incrementScore();
	int getScore();
};

class Map
{
private:
	char** map;
public:
	Map();
	~Map();
	void setMap();
	void drawMap();
	void setCell(int x, int y, char value);
	char getCell(int x, int y);
};

class Snake //pos->head, len, direction, velocity
{
private:
	pair<int, int> head;
	Direction dir;
	bool gameOver;
public:
	Snake();
	pair<int,int> getPosition();
	void setPosition(Map* mPtr);
	void getDirection();
	void move(Player* pPtr);
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

