#include "myclass.h"
#include <iostream>

template <class T>
void MySwap(T& arg1, T& arg2){
    T tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
}

int main()
{
    int a = 1, b = 2;
    std::cout << a << b << '\n';
    MySwap(a, b);
    std::cout << a << b << '\n';

    std::string str1 = "hello", str2 = "world";
    std::cout << str1 << str2 << '\n';
    MySwap(str1, str2);
    std::cout << str1 << str2 << '\n';

    MyClass<int,int> my_class(1, 2);
    std::cout << my_class.var1 << my_class.var2 << '\n';
    MySwap(my_class.var1, my_class.var2);
    std::cout << my_class.var1 << my_class.var2 << '\n';
}
