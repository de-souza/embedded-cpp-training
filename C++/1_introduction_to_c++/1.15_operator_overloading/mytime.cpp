#include "mytime.h"
#include <iostream>
#include <iomanip>

MyTime::MyTime(const int hours, const int minutes, const int seconds)
{
    mHours = hours;
    mMinutes = minutes;
    mSeconds = seconds;
}

MyTime& MyTime::operator+=(const MyTime &rhs)
{
    mSeconds += rhs.mSeconds;
    mMinutes += rhs.mMinutes + mSeconds/60;
    mHours += rhs.mHours + mMinutes/60;
    mSeconds %= 60;
    mMinutes %= 60;
    return *this;
}

MyTime operator+(MyTime lhs, const MyTime &rhs)
{
    lhs += rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream &os, const MyTime time)
{
    return os << std::setfill('0') << std::setw(2) << time.mHours << ":"
              << std::setw(2) << time.mMinutes << ":"
              << std::setw(2) << time.mSeconds;
}
