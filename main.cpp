#include "Factory.h"
#include "Interface.h"

using namespace std;

int main()
{
    Factory factory;

    while (true)
    {
        Interface* ptr = factory.buildScreen();

        if (ptr == nullptr)
            break;

        ptr->action();
    }
}
