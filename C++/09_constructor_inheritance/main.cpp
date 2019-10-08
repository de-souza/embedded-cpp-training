/* How inheritance affects class constructors and destructors. */
#include "parent.h"
#include "child.h"

int main()
{
    Parent* pParent = new Parent;
    delete pParent;

    Child* pChild = new Child("Eve");
    delete pChild;
}
