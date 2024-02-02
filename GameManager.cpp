#include "Components.h"
#include <conio.h>
#include <Windows.h>

/*Creating objects of the game elements to manage the game*/
GameManager::GameManager()
{
	mapPtr = new Map;
	snakePtr = new Snake;
	playerPtr = new Player;
}

/*Deallocating the memory*/
GameManager::~GameManager()
{
	delete mapPtr;
	delete snakePtr;
	delete playerPtr;
}

/*This function runs the game*/
void GameManager::run() const
{
	while (!snakePtr->game_is_over()) { //game loop
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 }); //instead of clear screen
		//Adjusting difficulty by changing the delay time
		if (playerPtr->getScore() < 50)
			Sleep(120);
		else if (playerPtr->getScore() < 200)
			Sleep(80);
		else if (playerPtr->getScore() < 500)
			Sleep(50);
		else
			Sleep(30);

		mapPtr->setMap();	//setting map symbols in the 2D array
		snakePtr->setOnMap(mapPtr); //setting snake symbols on the map
		mapPtr->drawMap();	//printing the map
		snakePtr->getDirection();	//getting snake's direction
		snakePtr->move(mapPtr, playerPtr); //snake's movement

		cout << "\nUse arrows or wasd to move..\n";
		cout << "\nName : " << playerPtr->getName() << "\n";
		cout << "Score : " << playerPtr->getScore() << "\n";
	}
	system("cls");
	cout << "\nGAME OVER!\n";
	cout << "\nYOUR SCORE IS : " << playerPtr->getScore() << "\n\n";
	playerPtr->getTopTen(); //printing top 10 list
	playerPtr->saveResults(); //saving the top 10 to a text file
}
