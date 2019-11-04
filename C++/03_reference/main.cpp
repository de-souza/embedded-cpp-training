/* How to use references in functions. */
#include <algorithm>
#include <iostream>

void sort_integers(int* pA, int* pB)  // C style, with pointers
{
    if (*pA > *pB)
        std::swap(*pA, *pB);
}

void SortIntegers(int& rA, int& rB)  // C++ style, with references
{
    if (rA > rB)
        std::swap(rA, rB);
}

int main()
{
    int a = 2;
    int b = 1;
    std::cout << "a = " << a << ", b = " << b << '\n'
              << "sort_integers(&a, &b)\n";
    sort_integers(&a, &b);
    std::cout << "a = " << a << ", b = " << b << '\n'
              << "SortIntegers(b, a)\n";
    SortIntegers(b, a);
    std::cout << "a = " << a << ", b = " << b << '\n';
}
