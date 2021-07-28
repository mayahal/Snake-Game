#include "WelcomeScreen.h"
#include "Printer.h"
#include "Console.h"

#include <iostream>

using namespace std;

WelcomeScreen::WelcomeScreen(Factory& factory, Values& values) : 
    Interface(factory, values)
{}

void WelcomeScreen::welcomeScreen()
{
    Console::setColor(consoleColor::lightGray);
    Printer::printText("Welcome to Snake");
    Printer::printText("Developed by Maya Halas");
    Printer::printText("2021");
    Printer::printPause();
    Printer::clearScreen();
}

void WelcomeScreen::action()
{
    welcomeScreen();
    factory.changeScreen = Factory::Screen::Menu;
}
