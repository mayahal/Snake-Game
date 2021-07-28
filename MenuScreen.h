#pragma once
#include "Interface.h"

class MenuScreen : public Interface
{
public:
    MenuScreen(Factory& factory, Values& values);

    void action() override;
};