#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
#include <queue>
#include <fstream>
//Map dimensions
#define HEIGHT 22	
#define WIDTH 35
using namespace std;

enum Direction { STOP = 0, UP, DOWN, RIGHT, LEFT };

/*This class represents the player information like name and score.
It manipulates the score*/
class Player //add name
{
private:
	int score;
	string name;
	vector<pair<int, string>> rank;
public:
	Player();
	void incrementScore();
	int getScore() const;
	string getName() const;
	void getTopTen();
	void saveResults();
};

/*This class represents the map that the snake moves in and it's responsible
for generating the fruit*/
class Map
{
private:
	char** map;
	pair<int, int> fruit;
public:
	Map();
	~Map();
	void setMap();
	void drawMap() const;
	void setCell(const int& x, const int& y, const char& value);
	char getCell(const int& x, const int& y) const;
	void generateFruit();
	pair<int, int> getFoodPos() const;
};

/*This class represents the snake itself. it handles the logic of snake's movement,
growth(when eating a fruit) and collision detection*/
class Snake //pos->head, len, direction
{
private:
	pair<int, int> head;
	deque<pair<int, int>> body;
	Direction dir;
	bool gameOver;
public:
	Snake();
	void setOnMap(Map* mPtr);
	void getDirection();
	void move(Map* mPtr, Player* pPtr);
	void grow();
	bool game_is_over() const;
	
};

/*This class combines all game parts together and manages the difficulty according to score*/
class GameManager
{
private:
	Map* mapPtr;
	Snake* snakePtr;
	Player* playerPtr;
public:
	GameManager();
	~GameManager();
	void run() const;
};

