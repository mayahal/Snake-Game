#pragma once
#include "Interface.h"

class ShowWinnersScreen : public Interface
{
private:
    void showWinners();

public:
    ShowWinnersScreen(Factory& factory, Values& values);

    void action() override;
};