#include <iostream>
#include "Components.h"
#include <Windows.h>
using namespace std;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {
    ShowConsoleCursor(false); //to hide the blinking curser
    
    GameManager game;
    game.run();
    system("PAUSE>NULL");
}

//todo
/*
    - document this project
    - add ranking to be saved in a text file
    - add arrows movement
    - modify the readME
*/