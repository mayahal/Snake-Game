#include "MenuScreen.h"
#include "Printer.h"
#include <iostream>

MenuScreen::MenuScreen(Factory& factory, Values& values) : Interface(factory,values) {}

void MenuScreen::action()
{
    Printer::printText("This is a menu screen");
    Printer::printText("What do you want?");
    Printer::printText("1 - start new game");
    Printer::printText("2 - show top-5 winners");

    int choosePlayer;
    std::cin >> choosePlayer;
    switch (choosePlayer)
    {
    case 1: factory.changeScreen = Factory::Screen::Game; break;
    case 2: factory.changeScreen = Factory::Screen::ShowWinners; break;
    default: break;
    }
}