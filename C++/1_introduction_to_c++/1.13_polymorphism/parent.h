#ifndef PARENT_H
#define PARENT_H

class Parent
{
public:
    void Print();
    virtual void SuperPrint();
    virtual ~Parent() = default;
};

#endif // PARENT_H
