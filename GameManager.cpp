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
	//while (!playerPtr->game_is_over())
	system("cls");
	mapPtr->draw(snakePtr);
	//Sleep(50);
}
