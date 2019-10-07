#ifndef MYCLASS_H
#define MYCLASS_H


class MyClass
{
public:
    MyClass();      // Constructor (no type is required for constuctors and destructors).
    MyClass(int a); // Overriden constructor.
    ~MyClass();     // Destructor.
    int i = 0;
    void Display();
    void Display2();
};

#endif // MYCLASS_H
