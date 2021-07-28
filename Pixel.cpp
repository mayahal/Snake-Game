#include "Pixel.h"
#include "Printer.h"
#include "Console.h"
#include "Field.h"

Pixel::Pixel(const Field& field, int y, int x, char value, consoleColor color) 
    : field(field)
    , y(y)
    , x(x)
    , value(value)
    ,color(color)
{
    isWall = x == 0 || y == 0 || y == field.getHeight() - 1 || x == field.getWidth() - 1;
}

void Pixel::print()
{
    if (isWall) 
    {
        Console::setColor(color);
        Printer::printValue('#');
    }
    else
    {
        Console::setColor(color);
        Printer::printValue(value);
    }
}

void Pixel::setValue(char value)
{
    if (this->value != value)
    {
        this->value = value;
        shouldUpdated = true;
    }
}

void Pixel::show()
{
    if (shouldUpdated)
    {
        Console::setPos(y, x);
        print();
        shouldUpdated = false;
    }
}

void Pixel::setCol(consoleColor color)
{
    if (this->color != color)
    {
        this->color = color;
    }
}

void Pixel::setColorAndValue(consoleColor color, char value)
{
    if (this->color != color)
    {
        this->color = color;
    }

    if (this->value != value)
    {
        this->value = value;
        shouldUpdated = true;
    }
}