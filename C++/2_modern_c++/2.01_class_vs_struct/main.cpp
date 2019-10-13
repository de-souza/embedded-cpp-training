/* How structures can contain functions in C++. */
#include <iostream>
#include <memory>

int main()
{
    struct MyStruct {
        int i;
        void clear() {i = 0;}
    };
    auto p = std::make_unique<MyStruct>();
    p->i = 2;
    std::cout << "p->i = " << p->i << '\n'
              << "p->clear()" << '\n';
    p->clear();
    std::cout << "p->i = " << p->i << '\n';
}
