#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
    Integer(const int i);
    Integer(const Integer &other);
    int content;
    int* pContent;
    void Display();
};

#endif // INTEGER_H
