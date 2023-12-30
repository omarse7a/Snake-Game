#include "Components.h"
#include <conio.h>
#include <Windows.h>

GameManager::GameManager()
{
	mapPtr = new Map;
	snakePtr = new Snake;
	playerPtr = new Player;
}

void GameManager::run()
{
	
	while (!snakePtr->game_is_over()) {
		//system("cls");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 }); //instead of clear screen and the sleep
		mapPtr->setMap();
		snakePtr->getDirection();
		snakePtr->move(mapPtr, playerPtr);
		snakePtr->setOnMap(mapPtr);
		mapPtr->drawMap();
		cout << "\nScore : " << playerPtr->getScore() << "\n";
	}
}
