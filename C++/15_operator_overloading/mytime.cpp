#include "mytime.h"
#include <iostream>
#include <iomanip>

MyTime::MyTime(const int h, const int m, const int s)
{
    Hours = h;
    Minutes = m;
    Seconds = s;
}

MyTime& MyTime::operator+=(const MyTime &rhs)
{
    Seconds += rhs.Seconds;
    Minutes += Seconds < 60 ? rhs.Minutes : rhs.Minutes + 1;
    Hours += Minutes < 60 ? rhs.Hours : rhs.Hours + 1;
    Seconds %= 60;
    Minutes %= 60;
    return *this;
}

MyTime operator+(MyTime lhs, const MyTime &rhs)
{
    lhs += rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream &os, const MyTime time)
{
    return os << std::setfill('0') << std::setw(2) << time.Hours << ":"
              << std::setw(2) << time.Minutes << ":"
              << std::setw(2) << time.Seconds;
}
