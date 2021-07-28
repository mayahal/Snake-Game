#pragma once
#include "Interface.h"
#include "Level.h"

class WelcomeScreen : public Interface
{
private:
    Level level;
    void welcomeScreen();

public:
    WelcomeScreen(Factory& factory, Values& values);
    void action() override;
};