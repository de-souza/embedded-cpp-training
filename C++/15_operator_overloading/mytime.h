#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>

class MyTime
{
public:
    MyTime(int h, int m, int s);
    int Hours;
    int Minutes;
    int Seconds;
    MyTime& operator+=(const MyTime& rhs);
    friend MyTime operator+(MyTime lhs, const MyTime& rhs) {
        lhs += rhs;
        return lhs;
    }
    friend std::ostream& operator<<(std::ostream& os, const MyTime time)
    {
        os << std::setfill('0') << std::setw(2) << time.Hours << ":";
        os << std::setfill('0') << std::setw(2) << time.Minutes << ":";
        os << std::setfill('0') << std::setw(2) << time.Seconds;
        return os;
    }
};

#endif // MYTIME_H
