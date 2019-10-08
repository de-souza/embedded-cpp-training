#pragma once

class Integer
{
public:
    Integer(int i);
    Integer(const Integer &other);
    int Content;
    int* pContent;
    void Print();
};
