
#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <deque>
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
	pair<int, int> fruit;
public:
	Map();
	~Map();
	void setMap();
	void drawMap();
	void setCell(int x, int y, char value);
	char getCell(int x, int y);
	void generateFruit();
	pair<int, int> getFoodPos();
};


class Snake //pos->head, len, direction, velocity
{
private:
	pair<int, int> head;
	deque<pair<int, int>> body;
	Direction dir;
	//velocity->sleep
	bool gameOver;
public:
	Snake();
	pair<int,int> getPosition();
	void setOnMap(Map* mPtr);
	void getDirection();
	void move(Map* mPtr, Player* pPtr);
	void grow();
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

