#include "Components.h"

Map::Map() {
	map = new char* [HEIGHT+2];
	for (int i = 0; i < HEIGHT+2; i++)
	{
		map[i] = new char[WIDTH+2];
	}
}
Map::~Map() {
	for (int i = 0; i < HEIGHT+2; i++)
		delete[] map[i];
	delete[] map;
}

void Map::setMap() {
	for (int i = 0; i < HEIGHT+2; i++) {
		for (int j = 0; j < WIDTH+2; j++) {
			if (i == 0 || i == HEIGHT+1) map[i][j] = '#';
			else if (j == 0 || j == WIDTH+1) map[i][j] = '#';
			else map[i][j] = ' ';
		}
	}
}

void Map::drawMap()
{
	for (int i = 0; i < HEIGHT + 2; i++) {
		for (int j = 0; j < WIDTH + 2; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void Map::setCell(int x, int y, char value)
{
	map[x][y] = value;
}

char Map::getCell(int x, int y)
{
	return map[x][y];
}


//void Map::generateFruit() {
//	srand(0);
//	fruitX = rand() % (width - 1);
//	fruitY = rand() % (height - 1);
//}
//
//void Map::draw(Snake* sPtr) {
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			if (i == 0 || i == height - 1) cout << "#";
//			else if (j == 0 || j == width - 1) cout << "#";
//			else if (i == sPtr->getPosition().first && j == sPtr->getPosition().second) cout << "O";
//			else if (i == fruitY && j == fruitX) cout << "$";
//			else cout << " ";
//		}
//		cout << endl;
//	}
//}
//
//int Map::getFruitX() {
//	return fruitX;
//}
//int Map::getFruitY() {
//	return fruitY;
//}