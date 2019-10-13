#include "counter.h"

int Counter::Count()
{
    static int cnt;
    return cnt++;
}
