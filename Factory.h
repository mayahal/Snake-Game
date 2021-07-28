#pragma once
#include "Values.h"

class Interface;

class Factory
{
public:
    enum class Screen { Welcome, Menu, ShowWinners, Game, End };
    Screen changeScreen = Screen::Welcome;
    Values values;

    Interface* buildScreen();
};
