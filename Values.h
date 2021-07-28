#pragma once
#include <string>

struct Values
{
	bool gameOver = false;
	int score = 0;
	std::string nameofWinner;
	std::string path = "List of winners.txt";
};