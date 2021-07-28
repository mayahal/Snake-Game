#pragma once
#include "Interface.h"
#include "Pixel.h"
#include "Dir.h"
#include "Field.h"
#include "Level.h"
#include <vector>

class GameScreen : public Interface
{
public:
    GameScreen(Factory& factory, Values& values);

    void action() override;
private:    
    void gameScreen();
    void generateApple();
    void input();
    void playerMove();
    void logic();
    void move(int y, int x);
    void setNamePlayer();

    
    Level level;
    Field newField;

    Dir playerDir = Dir::right;
    int playerX;
    int playerY;
    int appleX, appleY;
    std::vector<int> playerTailX;
    std::vector<int> playerTailY;
};