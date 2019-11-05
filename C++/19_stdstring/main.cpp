#include <iostream>

int main()
{
    std::string short_str = "Hello World!";
    std::string long_str = short_str.substr(0, 5);
    std::cout << long_str << '\n';
}
