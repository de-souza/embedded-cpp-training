#pragma once

#include "firstparent.h"
#include "secondparent.h"

class Child: public FirstParent, public SecondParent
{
public:
    Child();
    ~Child();
};
