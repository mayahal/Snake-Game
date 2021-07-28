#include "Printer.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void Printer::printValue(char value)
{
    cout << value;
}

void Printer::clearScreen()
{
    system("cls");
}

void Printer::printText(const string& text)
{
    cout << text << endl;
}

void Printer::printTextValue(const string& text, int value)
{
    cout << text << value << endl;
}

void Printer::printPause()
{
    system("pause");
}

void Printer::printSleep(int delay)
{
    Sleep(delay);
}

void Printer::printSpace()
{
    cout << endl;
}