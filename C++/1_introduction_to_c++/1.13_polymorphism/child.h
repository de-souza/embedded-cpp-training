#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

class Child: public Parent
{
public:
    void Print();
    void SuperPrint();
};

#endif // CHILD_H
