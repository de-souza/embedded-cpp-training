#ifndef ABSTRACTPARENT_H
#define ABSTRACTPARENT_H

class AbstractParent
{
public:
    virtual ~AbstractParent() = default;
    virtual void Print() = 0;
};

#endif // ABSTRACTPARENT_H
