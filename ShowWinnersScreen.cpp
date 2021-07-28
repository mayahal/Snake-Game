#include "ShowWinnersScreen.h"
#include "Printer.h"
#include "Values.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

ShowWinnersScreen::ShowWinnersScreen(Factory& factory, Values& values) : Interface(factory,values) {}

void ShowWinnersScreen::showWinners()
{
    Printer::clearScreen();
    ifstream paramFile;
    paramFile.open(values.path);
    string line;
    string key;
    double value;
    map <int, string> params;
    Printer::printText("We are proud!");
    Printer::printSpace();
    while (paramFile.good())
    {
        getline(paramFile, line);
        istringstream ss(line);
        ss >> value >> key;
        params[value] = key;
    }

    bool itexist = false;
    int sizeMap = static_cast<int>(params.size());
    auto it = params.rbegin();

    if (sizeMap == 0)
    {
        cout << "Here can be your name!" << endl;
    }
    else
    {
        if (sizeMap <= 5)
        {
            for (int i = 0; i < sizeMap; i++) {
                std::cout << "Score: " << it->first << " Name of winner: " << it->second << std::endl;
                it++;
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                std::cout << "Score: " << it->first << " Name of winner: " << it->second << std::endl;
                it++;
            }
            cout << endl;
        }
    }
}

void ShowWinnersScreen::action()
{
    Printer::printText("Winners");
    showWinners();
    system("pause");
    Printer::clearScreen();

    factory.changeScreen = Factory::Screen::Menu;
}