#include "myclass.h"
#include <iostream>

MyClass::MyClass()
{
    // Since C++11, variables can be initialised in the header file.
}

MyClass::MyClass(int a)
{
    i = a;
}

MyClass::~MyClass()
{

}

void MyClass::Display()
{
    std::cout << i << '\n';
}
