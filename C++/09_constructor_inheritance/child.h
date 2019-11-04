#ifndef CHILD_H
#define CHILD_H

#include "parent.h"
#include <string>

class Child: public Parent
{
public:
    Child();
    Child(const std::string& name);
    ~Child();
};

#endif // CHILD_H
