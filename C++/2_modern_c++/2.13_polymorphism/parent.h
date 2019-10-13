#ifndef PARENT_H
#define PARENT_H

class Parent
{
public:
    virtual ~Parent() = default;
    void RegularDisplay();
    virtual void VirtualDisplay();
};

#endif // PARENT_H
