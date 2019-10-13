#include "integer.h"
#include <iostream>

Integer::Integer(int i)
{
    content = i;
    pContent = &content;
}

Integer::Integer(const Integer &other)
{
    content = other.content;
    pContent = &content;  // don't copy the pointer, create a new one
}

void Integer::Display()
{
    std::cout << "*pContent = " << *pContent << '\n';
}
