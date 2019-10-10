#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime
{
public:
    int Hours;
    int Minutes;
    int Seconds;
    MyTime(const int h, const int m, const int s);
    MyTime& operator+=(const MyTime& rhs);
    friend MyTime operator+(MyTime lhs, const MyTime& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MyTime time);
};

#endif // MYTIME_H
