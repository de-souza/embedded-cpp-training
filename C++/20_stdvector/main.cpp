#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v(1000);
    std::iota (std::begin(v), std::end(v), 1);
    for (int i: v)
        std::cout << i << ' ';
}
