#pragma once
#include "Interface.h"

#include <map>

class EndScreen : public Interface
{
public:
    EndScreen(Factory& factory, Values& values);

    void setMapToFile(const std::map<int, std::string>& winners);
    void endScreen();
    void action() override;
};
