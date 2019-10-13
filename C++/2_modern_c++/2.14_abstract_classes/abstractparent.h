#ifndef ABSTRACTPARENT_H
#define ABSTRACTPARENT_H

class AbstractParent
{
public:
    virtual ~AbstractParent() = default;
    virtual void Display() = 0;
};

#endif // ABSTRACTPARENT_H
