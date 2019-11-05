#ifndef CLASSES_H
#define CLASSES_H

class BaseA
{};

class DerivedA: public BaseA
{};

class BaseB
{
public:
    virtual ~BaseB() = default;
};

class DerivedB: public BaseB
{};

#endif // CLASSES_H
