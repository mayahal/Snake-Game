#pragma once
#include "Pixel.h"
#include <vector>

class Field
{
public:
	int getWidth() const;
	int getHeight() const;
	void resetField();
	void showField();
	Pixel& getPixel(int y, int x);

private:
	int height = 15;
	int width = 30;
	typedef std::vector<Pixel> Line;
	std::vector<Line> field;
};

