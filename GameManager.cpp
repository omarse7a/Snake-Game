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
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 }); //instead of clear screen
		
		mapPtr->setMap();
		snakePtr->setOnMap(mapPtr);
		snakePtr->getDirection();
		snakePtr->move(mapPtr, playerPtr);
		mapPtr->drawMap();
		cout << "\nScore : " << playerPtr->getScore() << "\n";
		
	}
	system("cls");
	cout << "GAME OVER!\n";
	cout << "\nYOUR SCORE IS : " << playerPtr->getScore() << "\n\n";
}
