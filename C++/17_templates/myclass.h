#ifndef MYCLASS_H
#define MYCLASS_H

template <class T, class U>
class MyClass
{
public:
    MyClass(T arg1, U arg2)
    {
        var1 = arg1;
        var2 = arg2;
    }
    T var1;
    U var2;
};

#endif // MYCLASS_H
