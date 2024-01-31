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
    srand(time(NULL)); //changing random seed
    ShowConsoleCursor(false); //to hide the blinking curser
 
    GameManager game;
    game.run();
    system("PAUSE>NULL");
}
