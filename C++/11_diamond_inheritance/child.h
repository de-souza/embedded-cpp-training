#ifndef CHILD_H
#define CHILD_H

#include "firstparent.h"
#include "secondparent.h"

class Child: public FirstParent, public SecondParent
{};

#endif // CHILD_H
