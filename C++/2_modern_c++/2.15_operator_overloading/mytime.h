#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime
{
public:
    MyTime(const int hours, const int minutes, const int seconds);
    MyTime& operator+=(const MyTime& rhs);
    friend MyTime operator+(MyTime lhs, const MyTime& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MyTime time);
private:
    int mHours;
    int mMinutes;
    int mSeconds;
};

#endif // MYTIME_H
