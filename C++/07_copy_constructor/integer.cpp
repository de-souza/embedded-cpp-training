#include "integer.h"
#include <iostream>

Integer::Integer(int i)
{
    Content = i;
    pContent = &Content;
}

Integer::Integer(const Integer &other)
{
    Content = other.Content;
    pContent = &Content;
}

void Integer::Print()
{
    std::cout << "*pContent = " << *pContent << std::endl;
}
