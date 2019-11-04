/* How structures can contain functions in C++. */
#include <iostream>

int main()
{
    struct MyStruct {
        int i;
        void clear() {i = 0;}
    };
    MyStruct s;
    s.i = 2;
    std::cout << "s.i = " << s.i << '\n';
    s.clear();
    std::cout << "s.clear()" << '\n'
              << "s.i = " << s.i << '\n';
}
