#include "mytime.h"

MyTime::MyTime(int h, int m, int s)
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
