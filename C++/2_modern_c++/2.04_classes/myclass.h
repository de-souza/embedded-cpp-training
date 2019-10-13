#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
public:
    MyClass();              // Constructor (no type is required for constuctors and destructors).
    MyClass(const int a);   // Overriden constructor.
    ~MyClass();             // Destructor.
    int i = 0;
    void Display();
};

#endif // MYCLASS_H
