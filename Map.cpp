#include "Components.h"

Map::Map() : width(50), height(20){
	generateFruit();
}

void Map::generateFruit() {
	srand(0);
	fruitX = rand() % (width - 1);
	fruitY = rand() % (height - 1);
}

void Map::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1) cout << "#";
			else if (j == 0 || j == width - 1) cout << "#";
			else if (i == fruitY && j == fruitX) cout << "$";
			else cout << " ";
		}
		cout << endl;
	}
}