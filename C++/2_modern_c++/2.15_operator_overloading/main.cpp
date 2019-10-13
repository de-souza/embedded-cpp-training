/* How to overload operators using class members and/or friend functions. */
#include "mytime.h"
#include <iostream>

int main()
{
    MyTime time_cnt(00, 00, 00);
    MyTime time_increment(07, 45, 35);

    time_cnt += time_increment;
    std::cout << time_cnt << '\n';

    time_cnt = time_cnt + time_increment;
    std::cout << time_cnt << '\n';

    time_cnt = time_increment + time_cnt;
    std::cout << time_cnt << '\n';
}
