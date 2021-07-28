#include "GameScreen.h"
#include "Printer.h"
#include "Console.h"
#include "Level.h"
#include "Dir.h"
#include "Keys.h"
#include "Field.h"
#include <map>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

GameScreen::GameScreen(Factory& factory, Values& values) :
    Interface(factory, values),
    playerX(newField.getWidth() / 2),
    playerY(newField.getHeight() / 2)
{}
const std::map<Level, int> levelMap =
{
    {Level::easy, 200},
    {Level::middle, 100 },
    {Level::hard, 50}
};
int getDelayTime(Level level)
{
    return levelMap.at(level);
}

void GameScreen::gameScreen()
{
    Printer::clearScreen();
    setNamePlayer();

    Printer::clearScreen();
    newField.resetField();
    generateApple();
    while (!values.gameOver)
    {
        newField.showField();
        input();
        playerMove();
        Printer::printSleep(getDelayTime(level));
    }
}

void GameScreen::setNamePlayer()
{
    Printer::clearScreen();
    Printer::printText("Start a new game");
    Printer::printText("Enter your name: ");
    
    cin.ignore();
    getline(std::cin, values.nameofWinner);
    Printer::clearScreen();

    Printer::printText("Choose the level");
    Printer::printText("1 - easy");
    Printer::printText("2 - middle");
    Printer::printText("3 - hard");
    int a;
    std::cin >> a;
    switch (a)
    {
    case 1: level = Level::easy; break;
    case 2: level = Level::middle; break;
    case 3: level = Level::hard; break;
    default: break;
    }
}
void GameScreen::generateApple()
{
    do {
        appleX = Console::getRandomInt(1, newField.getWidth() - 2);
        appleY = Console::getRandomInt(1, newField.getHeight() - 2);
    } while (appleX == playerX && appleY == playerY);

    newField.showField();
    newField.getPixel(appleY, appleX).setColorAndValue(consoleColor::green, '@');
}
void GameScreen::input()
{
    if (_kbhit())
    {
        int key = _getch();
        switch (key)
        {
        case Keys::a: playerDir = Dir::left; break;
        case Keys::d: playerDir = Dir::right; break;
        case Keys::s: playerDir = Dir::down; break;
        case Keys::w: playerDir = Dir::up; break;
        case Keys::escape: values.gameOver = true;
        default: break;
        }
    }
}
void GameScreen::logic()
{
    for (int i = 0; i < playerTailX.size(); i++)
    {
        if (playerX == playerTailX[i] && playerY == playerTailY[i])
            values.gameOver = true;
    }

    if (playerX < 1)
        playerX = newField.getWidth() - 2;
    else if (playerX > newField.getWidth() - 2)
        playerX = 1;

    if (playerY < 1)
        playerY = newField.getHeight() - 2;
    else if (playerY > newField.getHeight() - 2)
        playerY = 1;

    if (appleX == playerX && appleY == playerY)
    {
        values.score++;
        generateApple();
        playerTailX.push_back(0);
        playerTailY.push_back(0);
    }
}
void GameScreen::move(int y, int x)
{
    if (playerTailX.empty())
        newField.getPixel(playerY, playerX).setValue(' ');
    playerX += x;
    playerY += y;
    logic();

    newField.getPixel(playerY, playerX).setColorAndValue(consoleColor::red, 'O');
}
void GameScreen::playerMove()
{
    if (!playerTailX.empty())
    {
        int lastY = playerTailY[playerTailY.size() - 1];
        int lastX = playerTailX[playerTailX.size() - 1];
        newField.getPixel(lastY, lastX).setValue(' ');
    }

    for (int i = playerTailX.size() - 1; i >= 1; i--)
    {
        playerTailX[i] = playerTailX[i - 1];
        playerTailY[i] = playerTailY[i - 1];
    }

    if (!playerTailX.empty())
    {
        playerTailX[0] = playerX;
        playerTailY[0] = playerY;
        newField.getPixel(playerY,playerX).setValue('o');
    }
    switch (playerDir)
    {
    case Dir::down: move(1, 0); break;
    case Dir::up: move(-1, 0); break;
    case Dir::left: move(0, -1); break;
    case Dir::right: move(0, 1); break;
    default: break;
    }
}

void GameScreen::action()
{
    gameScreen();
    factory.changeScreen = Factory::Screen::End;
}