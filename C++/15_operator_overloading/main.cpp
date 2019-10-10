#include "mytime.h"
#include <iostream>

int main()
{
    MyTime time_cnt(00, 00, 00);
    MyTime time_increment(07, 45, 35);

    std::cout << time_cnt << std::endl;

    time_cnt += time_increment;
    std::cout << time_cnt << std::endl;

    time_cnt = time_cnt + time_increment;
    std::cout << time_cnt << std::endl;
}
