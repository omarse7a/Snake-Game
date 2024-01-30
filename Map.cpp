#include "Components.h"

/*This constructor allocates memory for the 2D char array map and 
generates a fruit position on the map to start the game*/
Map::Map() {
	map = new char* [HEIGHT+2]; //allocating the # of rows
	for (int i = 0; i < HEIGHT+2; i++)
	{
		map[i] = new char[WIDTH+2]; //allocating # of columns for each row
	}
	generateFruit(); // fruit generation
}

/*Deallocating the memory when the object is destroyed*/
Map::~Map() {
	for (int i = 0; i < HEIGHT+2; i++)
		delete[] map[i];
	delete[] map;
}

/*Setting symbols for each position on the map*/
void Map::setMap() {
	for (int i = 0; i < HEIGHT+2; i++) {
		for (int j = 0; j < WIDTH+2; j++) {
			//the walls
			if (i == 0 || i == HEIGHT + 1) map[i][j] = '#';	
			else if (j == 0 || j == WIDTH + 1) map[i][j] = '#';
			//the fruit position
			else if (i == fruit.first && j == fruit.second) map[i][j] = '$';
			//the free space 
			else map[i][j] = ' ';
		}
	}
}

/*This draws the map content: walls, snake, fruit*/
void Map::drawMap() const
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE); //this handles the console output
	for (int i = 0; i < HEIGHT + 2; i++) {
		for (int j = 0; j < WIDTH + 2; j++) {
			if (map[i][j] == 'O')
				SetConsoleTextAttribute(hconsole, 10); //makes the snake's head color light green
			else if (map[i][j] == 'o')
				SetConsoleTextAttribute(hconsole, 2); //makes the snake's tail color green
			else if (map[i][j] == '$')
				SetConsoleTextAttribute(hconsole, 4); //makes the fruit's color red
			else
				SetConsoleTextAttribute(hconsole, 7); //returns output color back to white
			cout << map[i][j];	//prints the already set symbols of the map
		}
		cout << endl;
	}
}

/*It sets specific cell on the map with a specific symbol*/
void Map::setCell(const int& x, const int& y, const char& value)
{
	map[x][y] = value;
}

/*It gets specific cell's symbol*/
char Map::getCell(const int& x, const int& y) const
{
	return map[x][y];
}

/*Generates a fruit on a random position on map*/
void Map::generateFruit() {
	fruit.first = rand() % HEIGHT;
	fruit.second = rand() % WIDTH;
}

/*It gets the fruit position on the map*/
pair<int, int> Map::getFoodPos() const
{
	return fruit;
}