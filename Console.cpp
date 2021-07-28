#include "Console.h"
#include "consoleColor.h"
#include <Windows.h>


void Console::setPos(int y, int x) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Console::getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Console::setColor(consoleColor text, consoleColor background) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((static_cast<int>(background) << 4) | static_cast<int>(text)));
}