#include "Factory.h"
#include "GameScreen.h"
#include "WelcomeScreen.h"
#include "EndScreen.h"
#include "ShowWinnersScreen.h"
#include "MenuScreen.h"

Interface* Factory::buildScreen()
{
    if (changeScreen == Screen::Welcome)
        return new WelcomeScreen(*this, values);
    else if (changeScreen == Screen::Menu)
        return new MenuScreen(*this, values);
    else if (changeScreen == Screen::ShowWinners)
        return new ShowWinnersScreen(*this, values);
    else if (changeScreen == Screen::Game)
        return new GameScreen(*this, values);
    else if (changeScreen == Screen::End)
        return new EndScreen(*this, values);
    else
        return nullptr;
}