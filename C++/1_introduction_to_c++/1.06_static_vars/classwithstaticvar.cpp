#include "classwithstaticvar.h"

int ClassWithStaticVar::Cnt()
{
    static int cnt;
    return cnt++;
}
