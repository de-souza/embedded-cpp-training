#pragma once

#include "parent.h"

class Child: public Parent
{
public:
    Child();
    Child(const char* name);
    ~Child();
};
