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
	mapPtr->setMap();
	while (!snakePtr->game_is_over()) {
		//Sleep(50);
		//system("cls");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 }); //instead of clear screen and the sleep
		snakePtr->setPosition(mapPtr);
		mapPtr->drawMap();
		cout << "\nScore : " << playerPtr->getScore() << "\n";
	}
}
