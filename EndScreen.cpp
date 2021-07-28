#include "EndScreen.h"
#include "Console.h"
#include "Printer.h"

#include <sstream>
#include <fstream>

#include <map>

EndScreen::EndScreen(Factory& factory, Values& values) : 
    Interface(factory, values) 
    {}

void EndScreen::setMapToFile(const std::map<int, std::string>& winners)
{
    std::fstream f;

    f.open(values.path, std::fstream::app | std::fstream::in | std::fstream::out);
    for (auto itr = winners.begin(); itr != winners.end(); ++itr)
    {
        f << "" << itr->first << " " << itr->second << '\n';
    }
    f.close();
}

void EndScreen::endScreen()
{
    Printer::clearScreen();
    std::map<int, std::string> map;
    map.insert({ values.score, values.nameofWinner });
    setMapToFile(map);
    Printer::printText("Your result saved");

    Console::setColor(consoleColor::lightGray, consoleColor::black);
    Printer::printText("Game is over");
    Printer::printTextValue("Your score is ", values.score);
    Printer::printText("Good luck");
}

void EndScreen::action()
{
    endScreen();
    Printer::printPause();
    exit(0);
}