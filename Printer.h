#pragma once
#include <string>

namespace Printer
{
    void printValue(char value);
    void clearScreen();
    void printText(const std::string& text);
    void printTextValue(const std:: string& text, int value);
    void printPause();
    void printSleep(int delay);
    void printSpace();
};

