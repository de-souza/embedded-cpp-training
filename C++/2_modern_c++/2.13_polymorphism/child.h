#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

class Child: public Parent
{
public:
    void RegularDisplay();
    void VirtualDisplay();
};

#endif // CHILD_H
