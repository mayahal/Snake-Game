#pragma once
#include "consoleColor.h"

class Field;

class Pixel
{
private:
    const Field& field;
    int y, x;
    char value;
    bool isWall;
    bool shouldUpdated = true;
    consoleColor color;

    void print();


public:
    Pixel(const Field& field, int y, int x, char value = ' ', consoleColor color = consoleColor::magenta);

    void setColorAndValue(consoleColor color, char value);
    void setValue(char value);
    void show();
    void setCol(consoleColor color);
};

