#include "type.h"
#include "lib.h"

void f_App_Sum(u1 a0, u1 a1, u1 *psum)
{
    u1 sum;
    sum = a0 + a1;
    *psum = sum;
    return;
}