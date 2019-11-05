#include "classes.h"
#include <iostream>

int main () {
    BaseA* p_base_a = new BaseA;
    BaseB* p_base_b = new BaseB;
    BaseB* p_base_b_poly = new DerivedB;
    DerivedA* p_derived_a = new DerivedA;
    DerivedB* p_derived_b = new DerivedB;

    std::cout << "static_cast, Upcasting: ";
    p_base_a = static_cast<BaseA*>(p_derived_a);
    std::cout << "OK\n";

    std::cout << "static_cast, Downcasting: ";
    p_derived_a = static_cast<DerivedA*>(p_base_a);
    std::cout << "OK\n";

    std::cout << "static_cast, Unrelated Casting: ";
    // p_base_a = static_cast<BaseA*>(p_base_b);
    std::cout << "Compile-Time Error\n";

    std::cout << "dynamic_cast, Upcasting: ";
    p_base_a = dynamic_cast<BaseA*>(p_derived_a);
    std::cout << "OK\n";

    std::cout << "dynamic_cast, Downcasting from Non-Polymorphic Base: ";
    // p_derived_a = dynamic_cast<DerivedA*>(p_base_a);
    std::cout << "Compile-Time Error\n";

    std::cout << "dynamic_cast, Downcasting from Compatible Base: ";
    p_derived_b = dynamic_cast<DerivedB*>(p_base_b_poly);
    std::cout << (p_derived_b == nullptr ? "Run-Time Error\n" : "OK\n");

    std::cout << "dynamic_cast, Downcasting from Incompatible Base: ";
    p_derived_b = dynamic_cast<DerivedB*>(p_base_b);
    std::cout << (p_derived_b == nullptr ? "Run-Time Error\n" : "OK\n");

    std::cout << "dynamic_cast, Unrelated Casting: ";
     // p_base_a = dynamic_cast<BaseA*>(p_base_b);
    std::cout << "Compile-Time Error\n";
}
