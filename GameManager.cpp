#include "Components.h"

GameManager::GameManager()
{
	mapPtr = new Map;
	snakePtr = new Snake;
	playerPtr = new Player;
}

void GameManager::run()
{
	while (!playerPtr->game_is_over())
	{
		mapPtr->draw();
	}
}
