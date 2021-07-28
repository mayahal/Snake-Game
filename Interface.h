#pragma once
#include "Factory.h"
#include "Values.h"

class Interface
{
public:
    Interface(Factory& factory, Values& values);

    Factory& factory;
    Values& values;

    virtual void action() = 0;

    virtual ~Interface() = default;
};