/* How to use references in functions. */
#include <iostream>
#include <cstdlib>

void sort_integers(int* pA, int* pB)  // C style
{
    if (*pA > *pB) {
        int temp = *pA;
        *pA = *pB;
        *pB = temp;
    }
}

void SortIntegers(int& rA, int& rB)  // C++ style
{
    if (rA > rB) {
        int temp = rA;
        rA = rB;
        rB = temp;
    }
}

int main()
{
    int a = 2;
    int b = 1;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    sort_integers(&a, &b);
    std::cout << "\nsort_integers(&a, &b)\n"
              << "a = " << a << ", b = " << b << std::endl;
    SortIntegers(b, a);
    std::cout << "\nSortIntegers(b, a)\n"
              << "a = " << a << ", b = " << b << std::endl;
}
