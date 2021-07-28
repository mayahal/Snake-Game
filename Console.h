#pragma once
#include "consoleColor.h"

namespace Console
{
    void setPos(int y, int x);
    int getRandomInt(int min, int max);
    void setColor(consoleColor text, consoleColor background = consoleColor::black);
};

