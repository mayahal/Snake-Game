#include "Field.h"
#include "Console.h"

int Field::getWidth() const
{
	return width;
}
int Field::getHeight() const
{
	return height;
}

void Field::resetField()
{
    field.clear();

    for (int i = 0; i < getHeight(); i++)
    {
        field.push_back(std::vector<Pixel>());
        for (int j = 0; j < getWidth(); j++)
        {
            Pixel pix(*this, i, j);
            field[i].push_back(pix);
        }
    }
}

void Field::showField()
{
    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(); j++)
        {
            field[i][j].show();
        }
    }

    Console::setPos(0, 0);
}

Pixel& Field::getPixel(int y, int x)
{
    return field[y][x];
}
