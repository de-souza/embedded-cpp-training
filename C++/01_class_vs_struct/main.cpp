/* How structures can contain functions in C++. */
#include <iostream>
#include <cstdlib>

int main()
{
    struct MyStruct {
        int i;
        void clear() {i = 0;}
    };
    struct MyStruct* p = (struct MyStruct*) malloc(sizeof(*p));
    p->i = 2;
    std::cout << "p = " << p->i << std::endl;
    p->clear();
    std::cout << "p->clear()" << "\n"
              << "p = " << p->i << std::endl;
    free(p);
}
